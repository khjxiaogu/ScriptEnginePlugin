#pragma once
#include<functional>
#include <mutex>
#include <windows.h>
#define ON_K_EVENT (WM_USER|0X5224)
#define RUN_MAIN(X) (new KRunnable([=] {X}))->runTask();
LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
void createMessageWindow();
class KFuture {
	std::timed_mutex waitlock;
public:
	KFuture();
	virtual void start();
	virtual void complete();
	virtual bool wait(long time);
	virtual void wait();
	virtual bool isCompleted();
	virtual void fail();
};
class KRunnable
{
private:
	bool is_running = false;
	KFuture* future= 0;
protected:
	void Start() {
		is_running = true;
		if (future)
			future->start();
	}
	void End() {
		is_running = false;
		if (future)
			future->complete();
	}
	void Fail() {
		is_running = false;
		if (future)
			future->fail();
	}
public:
	bool is_timer = false;
	typedef std::function<void()> Runnable;
	Runnable run;
	KRunnable(Runnable func);
	KRunnable(Runnable func,KFuture * future);
	KRunnable* runTask();
	KRunnable* runTaskLater(long time);
	KRunnable* runTaskAsync();
	KRunnable* runTaskLaterAsync(long time);
	KRunnable* runTaskTimer(long first, long interval);
	KRunnable* runTaskTimerAsync(long first, long interval);
	KRunnable* cancelTimer();
	bool isRunning();
	bool setFuture(KFuture* future);
	KFuture* getFuture();
	friend LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
};


