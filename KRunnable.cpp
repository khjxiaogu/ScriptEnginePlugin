#include "KRunnable.h"
#include <thread>
static ATOM WindowClass;
HWND hwnd;
static LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	if (msg == ON_K_EVENT) {
		//prevent all exceptions
		KRunnable* kr = ((KRunnable*)lp);
		__try {
			kr->run();
		}
		__except (1) {

		}
		kr->End();
		__try {
			if(!kr->is_timer)
			delete kr;
		}
		__except (1) {}
		return 0;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}
void createMessageWindow() {
	HINSTANCE hinst = ::GetModuleHandle(NULL);
	if (!WindowClass) {
		//make a window class
		WNDCLASSEXW wcex = {
			/*size*/sizeof(WNDCLASSEX), /*style*/0, /*proc*/WndProc, /*extra*/0L,0L, /*hinst*/hinst,
			/*icon*/NULL, /*cursor*/NULL, /*brush*/NULL, /*menu*/NULL,
			/*class*/L"KHttpServer Msg wnd class", /*smicon*/NULL };
		WindowClass = ::RegisterClassExW(&wcex);
		if (!WindowClass)
			throw L"register window class failed.";
	}
	//create a window for this instance to receive messahes
	hwnd = ::CreateWindowExW(0, (LPCWSTR)MAKELONG(WindowClass, 0), L"KRunnableMsg",
		0, 0, 0, 1, 1, HWND_MESSAGE, NULL, hinst, NULL);
	if (!hwnd) throw "create message window failed.";
}

KRunnable::KRunnable(Runnable func) :run(func),future(NULL) {}

KRunnable::KRunnable(Runnable func, KFuture* future)
{
	KRunnable::KRunnable(func);
	this->future = future;
}

KRunnable* KRunnable::runTask()
{
	if (!is_running) {
		Start();
		if (!hwnd)
			createMessageWindow();
		PostMessageW(hwnd, ON_K_EVENT, NULL, (LPARAM)this);
	}
	return this;
}

KRunnable* KRunnable::runTaskLater(long time)
{
	if (!is_running) {
		Start();
		std::thread th([this, time] {
			std::this_thread::sleep_for(std::chrono::milliseconds(time));
			runTask();
			End();
			if (!is_timer)
				delete this;
			});
		th.detach();
	}
	return this;
}

KRunnable* KRunnable::runTaskAsync()
{
	Start();
	std::thread th([this] {
		try {
			this->run();
			End();
		}
		catch(...){
		
		}
		
		if (!is_timer)
		delete this;
		//delete th;
	});
	th.detach();
	return this;
}

KRunnable* KRunnable::runTaskLaterAsync(long time)
{
	Start();
	std::thread th([this, time] {
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
		run();
		End();
		if (!is_timer)
			delete this;
	});
	th.detach();
	return this;
}

KRunnable* KRunnable::runTaskTimer(long first, long interval)
{
	is_timer = true;
	Start();
	std::thread th([this,first,interval] {
		std::this_thread::sleep_for(std::chrono::milliseconds(first));
		while (is_timer) {
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (is_timer)
				runTask();
		}
		End();
		});
	th.detach();
	return this;
}

KRunnable* KRunnable::runTaskTimerAsync(long first, long interval)
{
	is_timer = true;
	Start();
	std::thread th([this, first, interval] {
		std::this_thread::sleep_for(std::chrono::milliseconds(first));
		while (is_timer) {
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			if (is_timer)
				runTaskAsync();
		}
		
		End();
		});
	th.detach();
	return this;
}

KRunnable* KRunnable::cancelTimer()
{
	is_timer = false;
	return this;
}


bool KRunnable::isRunning()
{
	return is_running;
}

bool KRunnable::setFuture(KFuture* future) {
	if (this->future == NULL || this->future->isCompleted()) {
		delete this->future;
		this->future = future;
		return true;
	}
	else
		return false;
}

KFuture* KRunnable::getFuture() {
	if (future)
		return future;
	else
		return (future = new KFuture());
}

KFuture::KFuture()
{
}

void KFuture::start()
{
	waitlock.lock();
}

void KFuture::complete()
{
	waitlock.unlock();
}

bool KFuture::wait(long time)
{
	std::unique_lock<std::timed_mutex> tlock(waitlock);
	return tlock.try_lock_for(std::chrono::milliseconds(time));
}

void KFuture::wait()
{
	waitlock.lock();
	waitlock.unlock();
}

bool KFuture::isCompleted()
{
	if (waitlock.try_lock()) {
		waitlock.unlock();
		return true;
	}
	else
		return false;
}
