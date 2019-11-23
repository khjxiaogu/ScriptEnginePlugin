// generated from gentext.pl Messages.xlsx
#include "tjs/tjsCommHead.h"

#include "tjs/tjsError.h"
#include "tjs/tjsTypes.h"
#include "string_table_resource.h"
#include "messages.h"
namespace TJS{
	static bool IS_LOAD_MESSAGE = false;
	static const int MAX_MESSAGE_LENGTH = 1024;
#define NUM_MESSAGE_MAX 73
	enum {
		NUM_TJS_INTERNAL_ERROR,
		NUM_TJS_WARNING,
		NUM_TJS_WARN_EVAL_OPERATOR,
		NUM_TJS_NARROW_TO_WIDE_CONVERSION_ERROR,
		NUM_TJS_VARIANT_CONVERT_ERROR,
		NUM_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT,
		NUM_TJS_IDEXPECTED,
		NUM_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT,
		NUM_TJS_CANNOT_MODIFY_LHS,
		NUM_TJS_INSUFFICIENT_MEM,
		NUM_TJS_CANNOT_GET_RESULT,
		NUM_TJS_NULL_ACCESS,
		NUM_TJS_MEMBER_NOT_FOUND,
		NUM_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN,
		NUM_TJS_NOT_IMPLEMENTED,
		NUM_TJS_INVALID_PARAM,
		NUM_TJS_BAD_PARAM_COUNT,
		NUM_TJS_INVALID_TYPE,
		NUM_TJS_SPECIFY_DIC_OR_ARRAY,
		NUM_TJS_SPECIFY_ARRAY,
		NUM_TJS_STRING_DEALLOC_ERROR,
		NUM_TJS_STRING_ALLOC_ERROR,
		NUM_TJS_MISPLACED_BREAK_CONTINUE,
		NUM_TJS_MISPLACED_CASE,
		NUM_TJS_MISPLACED_RETURN,
		NUM_TJS_STRING_PARSE_ERROR,
		NUM_TJS_NUMBER_ERROR,
		NUM_TJS_UNCLOSED_COMMENT,
		NUM_TJS_INVALID_CHAR,
		NUM_TJS_EXPECTED,
		NUM_TJS_SYNTAX_ERROR,
		NUM_TJS_PPERROR,
		NUM_TJS_CANNOT_GET_SUPER,
		NUM_TJS_INVALID_OPECODE,
		NUM_TJS_RANGE_ERROR,
		NUM_TJS_ACCESS_DENYED,
		NUM_TJS_NATIVE_CLASS_CRASH,
		NUM_TJS_INVALID_OBJECT,
		NUM_TJS_CANNOT_OMIT,
		NUM_TJS_CANNOT_PARSE_DATE,
		NUM_TJS_INVALID_VALUE_FOR_TIMESTAMP,
		NUM_TJS_EXCEPTION_NOT_FOUND,
		NUM_TJS_INVALID_FORMAT_STRING,
		NUM_TJS_DIVIDE_BY_ZERO,
		NUM_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA,
		NUM_TJS_SYMBOL,
		NUM_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT,
		NUM_TJS_NOBJECTS_WAS_NOT_FREED,
		NUM_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF,
		NUM_TJS_OBJECT_CREATION_HISTORY_DELIMITER,
		NUM_TJS_OBJECT_WAS_NOT_FREED_CRLF,
		NUM_TJS_OBJECT_WAS_NOT_FREED,
		NUM_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY,
		NUM_TJS_GROUP_BY_OBJECT_TYPE,
		NUM_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF,
		NUM_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY,
		NUM_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE,
		NUM_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF,
		NUM_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT,
		NUM_TJS_WRITE_ERROR,
		NUM_TJS_READ_ERROR,
		NUM_TJS_SEEK_ERROR,
		NUM_TJS_BYTE_CODE_BROKEN,
		NUM_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH,
		NUM_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG,
		NUM_TJS_UNKNOWN_FAILURE,
		NUM_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER,
		NUM_TJS_UNKNOWN_BIT_STRING_CHARACTER,
		NUM_TJS_UNKNOWN_HEX_STRING_CHARACTER,
		NUM_TJS_NOT_SUPPORTED_UUENCODE,
		NUM_TJS_NOT_SUPPORTED_BER,
		NUM_TJS_NOT_SUPPORTED_UNPACK_LP,
		NUM_TJS_NOT_SUPPORTED_UNPACK_P,
};
#ifdef STATIC_CH
#define IDS_TJS_INTERNAL_ERROR                                                   L"发生了内部错误"
#define IDS_TJS_WARNING                                                          L"警告："
#define IDS_TJS_WARN_EVAL_OPERATOR                                               L"使用运算符时非全局变量放在后面。（请注意：当前运算符在 TJS 2.4.1 有作改动）"
#define IDS_TJS_NARROW_TO_WIDE_CONVERSION_ERROR                                  L"不能将现有文字转换为 Unicode 文字。包含的有不能识别的文字在内。请确认 data 是否指定有误。"
#define IDS_TJS_VARIANT_CONVERT_ERROR                                            L"不能转换变量类型 %1 到 %2"
#define IDS_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT                                  L"不能将 %1 转换为 Object 类型"
#define IDS_TJS_IDEXPECTED                                                       L"请指定 ID"
#define IDS_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT                                  L"请使用 = 运算符来对比。（使用 '(A=B)!=0' 来与 0 作对比）"
#define IDS_TJS_CANNOT_MODIFY_LHS                                                L"进行了错误的表达式"
#define IDS_TJS_INSUFFICIENT_MEM                                                 L"内存不足"
#define IDS_TJS_CANNOT_GET_RESULT                                                L"不能从当前表达式中获取到结果"
#define IDS_TJS_NULL_ACCESS                                                      L"发生了访问 null 对象"
#define IDS_TJS_MEMBER_NOT_FOUND                                                 L"未找到 Member ""%1"""
#define IDS_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN                                   L"未指名 Member 未找到"
#define IDS_TJS_NOT_IMPLEMENTED                                                  L"调用了未实现的方法"
#define IDS_TJS_INVALID_PARAM                                                    L"参数不合法"
#define IDS_TJS_BAD_PARAM_COUNT                                                  L"参数个数有误"
#define IDS_TJS_INVALID_TYPE                                                     L"不是一个 function 或者 方法/属性 有误"
#define IDS_TJS_SPECIFY_DIC_OR_ARRAY                                             L"请声明为 Dictionary 或者 Array 对象类型"
#define IDS_TJS_SPECIFY_ARRAY                                                    L"请声明为 Array 对象"
#define IDS_TJS_STRING_DEALLOC_ERROR                                             L"不能释放 string 内存区域"
#define IDS_TJS_STRING_ALLOC_ERROR                                               L"不能创建 string 内存区域"
#define IDS_TJS_MISPLACED_BREAK_CONTINUE                                         L"不能写 ""break"" 或者 ""continue"" 到这里"
#define IDS_TJS_MISPLACED_CASE                                                   L"不能写 ""case"" 到这里"
#define IDS_TJS_MISPLACED_RETURN                                                 L"不能把 ""return"" 写到这里"
#define IDS_TJS_STRING_PARSE_ERROR                                               L"string/regxp/octet 处理时发生了错误"
#define IDS_TJS_NUMBER_ERROR                                                     L"number 处理时发生了错误"
#define IDS_TJS_UNCLOSED_COMMENT                                                 L"注释未关闭"
#define IDS_TJS_INVALID_CHAR                                                     L"未知字符：'%1'"
#define IDS_TJS_EXPECTED                                                         L"异常发生：%1"
#define IDS_TJS_SYNTAX_ERROR                                                     L"语法有误 （%1）"
#define IDS_TJS_PPERROR                                                          L"条件表达式错误"
#define IDS_TJS_CANNOT_GET_SUPER                                                 L"父类不存在或者不能定位到父类"
#define IDS_TJS_INVALID_OPECODE                                                  L"VM 代码有误"
#define IDS_TJS_RANGE_ERROR                                                      L"错误：取值范围以外"
#define IDS_TJS_ACCESS_DENYED                                                    L"对 只读/只写 属性进行了错误操作"
#define IDS_TJS_NATIVE_CLASS_CRASH                                               L"无效的 object context"
#define IDS_TJS_INVALID_OBJECT                                                   L"对象已无效"
#define IDS_TJS_CANNOT_OMIT                                                      L"不能在方法之外使用 ""..."""
#define IDS_TJS_CANNOT_PARSE_DATE                                                L"不正确的日期格式"
#define IDS_TJS_INVALID_VALUE_FOR_TIMESTAMP                                      L"不正确的 日期/时间 值"
#define IDS_TJS_EXCEPTION_NOT_FOUND                                              L"不能转换异常 因为 ""Exception"" 不存在"
#define IDS_TJS_INVALID_FORMAT_STRING                                            L"不正确的字符串格式"
#define IDS_TJS_DIVIDE_BY_ZERO                                                   L"被 0 整除了"
#define IDS_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA                                L"不能重新构造随机数列"
#define IDS_TJS_SYMBOL                                                           L"ID"
#define IDS_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT                           L"[TJS2 脚本之外]"
#define IDS_TJS_NOBJECTS_WAS_NOT_FREED                                           L"共计 %1 个对象未释放"
#define IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF                           L"\r\n                     "
#define IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER                                L"\n                     "
#define IDS_TJS_OBJECT_WAS_NOT_FREED_CRLF                                        L"对象 %1 [%2] 未释放。对象创建在：%2"
#define IDS_TJS_OBJECT_WAS_NOT_FREED                                             L"对象 %1 [%2] 未释放。对象创建在：%2"
#define IDS_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY                                 L"以对象类型和所在位置来分组"
#define IDS_TJS_GROUP_BY_OBJECT_TYPE                                             L"以为对象类型来分组"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF    L"%1 个： [%2]\r\n                     %3"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY         L"%1 个：[%2]\n                     %3"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE                  L"%1 个： [%2]"
#define IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF                        L"%4：运行代码在正在删除的进城中，对象 %1[%2] / 对象创建在：%3"
#define IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT                             L"%4：运行代码在正在删除的进城中，对象 %1[%2] / 对象创建在：%3"
#define IDS_TJS_WRITE_ERROR                                                      L"写入错误"
#define IDS_TJS_READ_ERROR                                                       L"读取错误"
#define IDS_TJS_SEEK_ERROR                                                       L"查询错误"
#define IDS_TJS_BYTE_CODE_BROKEN                                                 L"读取 Bytecode 错误。文件已损坏或者该文件不是 bytecode 文件。"
#define IDS_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH                             L"对象的哈希图与日志版本不一致"
#define IDS_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG                                    L"对象哈希图已损坏"
#define IDS_TJS_UNKNOWN_FAILURE                                                  L"未知错误：%08X"
#define IDS_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER                            L"未知打包/解包模板字符"
#define IDS_TJS_UNKNOWN_BIT_STRING_CHARACTER                                     L"未知 bit string 字符"
#define IDS_TJS_UNKNOWN_HEX_STRING_CHARACTER                                     L"未知 16 进制字符"
#define IDS_TJS_NOT_SUPPORTED_UUENCODE                                           L"不支持 uuencode"
#define IDS_TJS_NOT_SUPPORTED_BER                                                L"不支持 BER 压缩"
#define IDS_TJS_NOT_SUPPORTED_UNPACK_LP                                          L"不支持解包 'p'"
#define IDS_TJS_NOT_SUPPORTED_UNPACK_P                                           L"不支持解包 'p'"
#elif STATIC_EN
#define IDS_TJS_INTERNAL_ERROR                                                   L"Internal error"
#define IDS_TJS_WARNING                                                          L"Warning: "
#define IDS_TJS_WARN_EVAL_OPERATOR                                               L"Non-global post-! operator is used (note that the post-! operator behavior is changed on TJS2 version 2.4.1)"
#define IDS_TJS_NARROW_TO_WIDE_CONVERSION_ERROR                                  L"Cannot convert given narrow string to wide string"
#define IDS_TJS_VARIANT_CONVERT_ERROR                                            L"Cannot convert the variable type (%1 to %2)"
#define IDS_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT                                  L"Cannot convert the variable type (%1 to Object)"
#define IDS_TJS_IDEXPECTED                                                       L"Specify an ID"
#define IDS_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT                                  L"Substitution in boolean context (use form of '(A=B)!=0' to compare to zero)"
#define IDS_TJS_CANNOT_MODIFY_LHS                                                L"This expression cannot be used as a lvalue"
#define IDS_TJS_INSUFFICIENT_MEM                                                 L"Insufficient memory"
#define IDS_TJS_CANNOT_GET_RESULT                                                L"Cannot get the value of this expression"
#define IDS_TJS_NULL_ACCESS                                                      L"Accessing to null object"
#define IDS_TJS_MEMBER_NOT_FOUND                                                 L"Member ""%1"" does not exist"
#define IDS_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN                                   L"Member does not exist"
#define IDS_TJS_NOT_IMPLEMENTED                                                  L"Called method is not implemented"
#define IDS_TJS_INVALID_PARAM                                                    L"Invalid argument"
#define IDS_TJS_BAD_PARAM_COUNT                                                  L"Invalid argument count"
#define IDS_TJS_INVALID_TYPE                                                     L"Not a function or invalid method/property type"
#define IDS_TJS_SPECIFY_DIC_OR_ARRAY                                             L"Specify a Dictionary object or an Array object"
#define IDS_TJS_SPECIFY_ARRAY                                                    L"Specify an Array object"
#define IDS_TJS_STRING_DEALLOC_ERROR                                             L"Cannot free the string memory block"
#define IDS_TJS_STRING_ALLOC_ERROR                                               L"Cannot allocate the string memory block"
#define IDS_TJS_MISPLACED_BREAK_CONTINUE                                         L"Cannot place ""break"" or ""continue"" here"
#define IDS_TJS_MISPLACED_CASE                                                   L"Cannot place ""case"" here"
#define IDS_TJS_MISPLACED_RETURN                                                 L"Cannot place ""return"" here"
#define IDS_TJS_STRING_PARSE_ERROR                                               L"Un-terminated string/regexp/octet literal"
#define IDS_TJS_NUMBER_ERROR                                                     L"Cannot be parsed as a number"
#define IDS_TJS_UNCLOSED_COMMENT                                                 L"Un-terminated comment"
#define IDS_TJS_INVALID_CHAR                                                     L"Invalid character '%1'"
#define IDS_TJS_EXPECTED                                                         L"Expected %1"
#define IDS_TJS_SYNTAX_ERROR                                                     L"Syntax error (%1)"
#define IDS_TJS_PPERROR                                                          L"Error in conditional compiling expression"
#define IDS_TJS_CANNOT_GET_SUPER                                                 L"Super class does not exist or cannot specify the super class"
#define IDS_TJS_INVALID_OPECODE                                                  L"Invalid VM code"
#define IDS_TJS_RANGE_ERROR                                                      L"The value is out of the range"
#define IDS_TJS_ACCESS_DENYED                                                    L"Invalid operation for Read-only or Write-only property"
#define IDS_TJS_NATIVE_CLASS_CRASH                                               L"Invalid object context"
#define IDS_TJS_INVALID_OBJECT                                                   L"The object is already invalidated"
#define IDS_TJS_CANNOT_OMIT                                                      L"""..."" is used out of functions"
#define IDS_TJS_CANNOT_PARSE_DATE                                                L"Invalid date format"
#define IDS_TJS_INVALID_VALUE_FOR_TIMESTAMP                                      L"Invalid value for date/time"
#define IDS_TJS_EXCEPTION_NOT_FOUND                                              L"Cannot convert exception because ""Exception"" does not exist"
#define IDS_TJS_INVALID_FORMAT_STRING                                            L"Invalid format string"
#define IDS_TJS_DIVIDE_BY_ZERO                                                   L"Division by zero"
#define IDS_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA                                L"Cannot reconstruct random seeds"
#define IDS_TJS_SYMBOL                                                           L"ID"
#define IDS_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT                           L"[out of TJS2 script]"
#define IDS_TJS_NOBJECTS_WAS_NOT_FREED                                           L"Total %1 Object(s) was not freed"
#define IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF                           L" <-- "
#define IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER                                L" <-- "
#define IDS_TJS_OBJECT_WAS_NOT_FREED_CRLF                                        L"Object %1 [%2] wes not freed / The object was created at : %2"
#define IDS_TJS_OBJECT_WAS_NOT_FREED                                             L"Object %1 [%2] wes not freed / The object was created at : %2"
#define IDS_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY                                 L"Group by object type and location where the object was created"
#define IDS_TJS_GROUP_BY_OBJECT_TYPE                                             L"Group by object type"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF    L"%1 time(s) : [%2] %3"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY         L"%1 time(s) : [%2] %3"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE                  L"%1 time(s) : [%2]"
#define IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF                        L"%4: Running code on deleting-in-progress object %1[%2] / The object was created at : %3"
#define IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT                             L"%4: Running code on deleting-in-progress object %1[%2] / The object was created at : %3"
#define IDS_TJS_WRITE_ERROR                                                      L"Write error"
#define IDS_TJS_READ_ERROR                                                       L"Read error"
#define IDS_TJS_SEEK_ERROR                                                       L"Seek error"
#define IDS_TJS_BYTE_CODE_BROKEN                                                 L"Bytecode read error. File is broken or it's not bytecode file."
#define IDS_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH                             L"Object Hash Map log version mismatch"
#define IDS_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG                                    L"Currupted Object Hash Map log"
#define IDS_TJS_UNKNOWN_FAILURE                                                  L"Unknown failure : %08X"
#define IDS_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER                            L"Unknown pack/unpack TEMPLATE charcter"
#define IDS_TJS_UNKNOWN_BIT_STRING_CHARACTER                                     L"Unknown bit string charcter"
#define IDS_TJS_UNKNOWN_HEX_STRING_CHARACTER                                     L"Unknown Hex string charcter"
#define IDS_TJS_NOT_SUPPORTED_UUENCODE                                           L"Not supported uuencode"
#define IDS_TJS_NOT_SUPPORTED_BER                                                L"Not supported BER"
#define IDS_TJS_NOT_SUPPORTED_UNPACK_LP                                          L"Not supported unpack 'p'"
#define IDS_TJS_NOT_SUPPORTED_UNPACK_P                                           L"Not supported unpack 'P'"
#elif STATIC_JP
#define IDS_TJS_INTERNAL_ERROR                                                   L"内部エラーが発生しました"
#define IDS_TJS_WARNING                                                          L"警告: "
#define IDS_TJS_WARN_EVAL_OPERATOR                                               L"グローバルでない場所で後置 ! 演算子が使われています(この演算子の挙動はTJS2 version 2.4.1 で変わりましたのでご注意ください)"
#define IDS_TJS_NARROW_TO_WIDE_CONVERSION_ERROR                                  L"文字列を UNICODE 文字列に変換できません。解釈できない文字が含まれてます。正しいデータが指定されているかを確認してください。データが破損している可能性もあります"
#define IDS_TJS_VARIANT_CONVERT_ERROR                                            L"%1 から %2 へ型を変換できません"
#define IDS_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT                                  L"%1 から Object へ型を変換できません。Object 型が要求される文脈で Object 型以外の値が渡されるとこのエラーが発生します"
#define IDS_TJS_IDEXPECTED                                                       L"識別子を指定してください"
#define IDS_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT                                  L"論理値が求められている場所で = 演算子が使用されています(== 演算子の間違いですか？代入した上でゼロと値を比較したい場合は、(A=B) != 0 の形式を使うことをお勧めします)"
#define IDS_TJS_CANNOT_MODIFY_LHS                                                L"不正な代入か不正な式の操作です"
#define IDS_TJS_INSUFFICIENT_MEM                                                 L"メモリが足りません"
#define IDS_TJS_CANNOT_GET_RESULT                                                L"この式からは値を得ることができません"
#define IDS_TJS_NULL_ACCESS                                                      L"null オブジェクトにアクセスしようとしました"
#define IDS_TJS_MEMBER_NOT_FOUND                                                 L"メンバ ""%1"" が見つかりません"
#define IDS_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN                                   L"メンバが見つかりません"
#define IDS_TJS_NOT_IMPLEMENTED                                                  L"呼び出そうとした機能は未実装です"
#define IDS_TJS_INVALID_PARAM                                                    L"不正な引数です"
#define IDS_TJS_BAD_PARAM_COUNT                                                  L"引数の数が不正です"
#define IDS_TJS_INVALID_TYPE                                                     L"関数ではないかプロパティの種類が違います"
#define IDS_TJS_SPECIFY_DIC_OR_ARRAY                                             L"Dictionary または Array クラスのオブジェクトを指定してください"
#define IDS_TJS_SPECIFY_ARRAY                                                    L"Array クラスのオブジェクトを指定してください"
#define IDS_TJS_STRING_DEALLOC_ERROR                                             L"文字列メモリブロックを解放できません"
#define IDS_TJS_STRING_ALLOC_ERROR                                               L"文字列メモリブロックを確保できません"
#define IDS_TJS_MISPLACED_BREAK_CONTINUE                                         L"""break"" または ""continue"" はここに書くことはできません"
#define IDS_TJS_MISPLACED_CASE                                                   L"""case"" はここに書くことはできません"
#define IDS_TJS_MISPLACED_RETURN                                                 L"""return"" はここに書くことはできません"
#define IDS_TJS_STRING_PARSE_ERROR                                               L"文字列定数/正規表現/オクテット即値が終わらないままスクリプトの終端に達しました"
#define IDS_TJS_NUMBER_ERROR                                                     L"数値として解釈できません"
#define IDS_TJS_UNCLOSED_COMMENT                                                 L"コメントが終わらないままスクリプトの終端に達しました"
#define IDS_TJS_INVALID_CHAR                                                     L"不正な文字です : '%1'"
#define IDS_TJS_EXPECTED                                                         L"%1 がありません"
#define IDS_TJS_SYNTAX_ERROR                                                     L"文法エラーです(%1)"
#define IDS_TJS_PPERROR                                                          L"条件コンパイル式にエラーがあります"
#define IDS_TJS_CANNOT_GET_SUPER                                                 L"スーパークラスが存在しないかスーパークラスを特定できません"
#define IDS_TJS_INVALID_OPECODE                                                  L"不正な VM コードです"
#define IDS_TJS_RANGE_ERROR                                                      L"値が範囲外です"
#define IDS_TJS_ACCESS_DENYED                                                    L"読み込み専用あるいは書き込み専用プロパティに対して行えない操作をしようとしました"
#define IDS_TJS_NATIVE_CLASS_CRASH                                               L"実行コンテキストが違います"
#define IDS_TJS_INVALID_OBJECT                                                   L"オブジェクトはすでに無効化されています"
#define IDS_TJS_CANNOT_OMIT                                                      L"""..."" は関数外では使えません"
#define IDS_TJS_CANNOT_PARSE_DATE                                                L"不正な日付文字列の形式です"
#define IDS_TJS_INVALID_VALUE_FOR_TIMESTAMP                                      L"不正な日付・時刻です"
#define IDS_TJS_EXCEPTION_NOT_FOUND                                              L"""Exception"" が存在しないため例外オブジェクトを作成できません"
#define IDS_TJS_INVALID_FORMAT_STRING                                            L"不正な書式文字列です"
#define IDS_TJS_DIVIDE_BY_ZERO                                                   L"0 で除算をしようとしました"
#define IDS_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA                                L"乱数系列を初期化できません(おそらく不正なデータが渡されました)"
#define IDS_TJS_SYMBOL                                                           L"識別子"
#define IDS_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT                           L"[TJSスクリプト管理外]"
#define IDS_TJS_NOBJECTS_WAS_NOT_FREED                                           L"合計 %1 個のオブジェクトが解放されていません"
#define IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF                           L"\r\n                     "
#define IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER                                L"\n                     "
#define IDS_TJS_OBJECT_WAS_NOT_FREED_CRLF                                        L"オブジェクト %1 [%2] が解放されていません。オブジェクト作成時の呼び出し履歴は以下の通りです:\r\n                     %3"
#define IDS_TJS_OBJECT_WAS_NOT_FREED                                             L"オブジェクト %1 [%2] が解放されていません。オブジェクト作成時の呼び出し履歴は以下の通りです:\n                     %3"
#define IDS_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY                                 L"オブジェクトのタイプとオブジェクト作成時の履歴による分類"
#define IDS_TJS_GROUP_BY_OBJECT_TYPE                                             L"オブジェクトのタイプによる分類"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF    L"%1 個 : [%2]\r\n                     %3"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY         L"%1 個 : [%2]\n                     %3"
#define IDS_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE                  L"%1 個 : [%2]"
#define IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF                        L"%4: 削除中のオブジェクト %1[%2] 上でコードが実行されています。このオブジェクトの作成時の呼び出し履歴は以下の通りです:\r\n                     %3"
#define IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT                             L"%4: 削除中のオブジェクト %1[%2] 上でコードが実行されています。このオブジェクトの作成時の呼び出し履歴は以下の通りです:\n                     %3"
#define IDS_TJS_WRITE_ERROR                                                      L"書き込みエラーが発生しました"
#define IDS_TJS_READ_ERROR                                                       L"読み込みエラーが発生しました。ファイルが破損している可能性や、デバイスからの読み込みに失敗した可能性があります"
#define IDS_TJS_SEEK_ERROR                                                       L"シークエラーが発生しました。ファイルが破損している可能性や、デバイスからの読み込みに失敗した可能性があります"
#define IDS_TJS_BYTE_CODE_BROKEN                                                 L"バイトコードファイル読み込みエラー。ファイルが壊れているかバイトコードとは異なるファイルです"
#define IDS_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH                             L"Object Hash Map ログのバージョンが一致しません"
#define IDS_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG                                    L"不正な Object Hash Map ログ"
#define IDS_TJS_UNKNOWN_FAILURE                                                  L"未知のエラー %08X"
#define IDS_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER                            L"不明な pack/unpack TEMPLATE 文字です"
#define IDS_TJS_UNKNOWN_BIT_STRING_CHARACTER                                     L"不明な bit string 文字です"
#define IDS_TJS_UNKNOWN_HEX_STRING_CHARACTER                                     L"不明な16進数文字です"
#define IDS_TJS_NOT_SUPPORTED_UUENCODE                                           L"uuencode はサポートしていません"
#define IDS_TJS_NOT_SUPPORTED_BER                                                L"BER圧縮はサポートしていません"
#define IDS_TJS_NOT_SUPPORTED_UNPACK_LP                                          L"'p' unpack はサポートしていません"
#define IDS_TJS_NOT_SUPPORTED_UNPACK_P                                           L"'P' unpack はサポートしていません"
#else

const tjs_char* RESOURCE_MESSAGE[NUM_MESSAGE_MAX];
const int RESOURCE_IDS[] = {
	IDS_TJS_INTERNAL_ERROR,
	IDS_TJS_WARNING,
	IDS_TJS_WARN_EVAL_OPERATOR,
	IDS_TJS_NARROW_TO_WIDE_CONVERSION_ERROR,
	IDS_TJS_VARIANT_CONVERT_ERROR,
	IDS_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT,
	IDS_TJS_IDEXPECTED,
	IDS_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT,
	IDS_TJS_CANNOT_MODIFY_LHS,
	IDS_TJS_INSUFFICIENT_MEM,
	IDS_TJS_CANNOT_GET_RESULT,
	IDS_TJS_NULL_ACCESS,
	IDS_TJS_MEMBER_NOT_FOUND,
	IDS_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN,
	IDS_TJS_NOT_IMPLEMENTED,
	IDS_TJS_INVALID_PARAM,
	IDS_TJS_BAD_PARAM_COUNT,
	IDS_TJS_INVALID_TYPE,
	IDS_TJS_SPECIFY_DIC_OR_ARRAY,
	IDS_TJS_SPECIFY_ARRAY,
	IDS_TJS_STRING_DEALLOC_ERROR,
	IDS_TJS_STRING_ALLOC_ERROR,
	IDS_TJS_MISPLACED_BREAK_CONTINUE,
	IDS_TJS_MISPLACED_CASE,
	IDS_TJS_MISPLACED_RETURN,
	IDS_TJS_STRING_PARSE_ERROR,
	IDS_TJS_NUMBER_ERROR,
	IDS_TJS_UNCLOSED_COMMENT,
	IDS_TJS_INVALID_CHAR,
	IDS_TJS_EXPECTED,
	IDS_TJS_SYNTAX_ERROR,
	IDS_TJS_PPERROR,
	IDS_TJS_CANNOT_GET_SUPER,
	IDS_TJS_INVALID_OPECODE,
	IDS_TJS_RANGE_ERROR,
	IDS_TJS_ACCESS_DENYED,
	IDS_TJS_NATIVE_CLASS_CRASH,
	IDS_TJS_INVALID_OBJECT,
	IDS_TJS_CANNOT_OMIT,
	IDS_TJS_CANNOT_PARSE_DATE,
	IDS_TJS_INVALID_VALUE_FOR_TIMESTAMP,
	IDS_TJS_EXCEPTION_NOT_FOUND,
	IDS_TJS_INVALID_FORMAT_STRING,
	IDS_TJS_DIVIDE_BY_ZERO,
	IDS_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA,
	IDS_TJS_SYMBOL,
	IDS_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT,
	IDS_TJS_NOBJECTS_WAS_NOT_FREED,
	IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF,
	IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER,
	IDS_TJS_OBJECT_WAS_NOT_FREED_CRLF,
	IDS_TJS_OBJECT_WAS_NOT_FREED,
	IDS_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY,
	IDS_TJS_GROUP_BY_OBJECT_TYPE,
	IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF,
	IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY,
	IDS_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE,
	IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF,
	IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT,
	IDS_TJS_WRITE_ERROR,
	IDS_TJS_READ_ERROR,
	IDS_TJS_SEEK_ERROR,
	IDS_TJS_BYTE_CODE_BROKEN,
	IDS_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH,
	IDS_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG,
	IDS_TJS_UNKNOWN_FAILURE,
	IDS_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER,
	IDS_TJS_UNKNOWN_BIT_STRING_CHARACTER,
	IDS_TJS_UNKNOWN_HEX_STRING_CHARACTER,
	IDS_TJS_NOT_SUPPORTED_UUENCODE,
	IDS_TJS_NOT_SUPPORTED_BER,
	IDS_TJS_NOT_SUPPORTED_UNPACK_LP,
	IDS_TJS_NOT_SUPPORTED_UNPACK_P,
};
void TVPLoadMessage() {
	if (IS_LOAD_MESSAGE) return;
	IS_LOAD_MESSAGE = true;
	tjs_char buffer[MAX_MESSAGE_LENGTH];
	HINSTANCE hInstance = ::GetModuleHandle(0);
	for (int i = 0; i < NUM_MESSAGE_MAX; i++) {
		int len = ::LoadString(hInstance, RESOURCE_IDS[i], buffer, MAX_MESSAGE_LENGTH);
		if (len <= 0) {
			buffer[0] = { 0 };
		}
		tjs_char* work = new tjs_char[len + 1];
		wcscpy_s(work, len + 1, buffer);
		RESOURCE_MESSAGE[i] = work;
	}
	TJSInternalError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INTERNAL_ERROR]);
	TJSWarning.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARNING]);
	TJSWarnEvalOperator.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARN_EVAL_OPERATOR]);
	TJSNarrowToWideConversionError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NARROW_TO_WIDE_CONVERSION_ERROR]);
	TJSVariantConvertError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_VARIANT_CONVERT_ERROR]);
	TJSVariantConvertErrorToObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT]);
	TJSIDExpected.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_IDEXPECTED]);
	TJSSubstitutionInBooleanContext.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT]);
	TJSCannotModifyLHS.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_MODIFY_LHS]);
	TJSInsufficientMem.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INSUFFICIENT_MEM]);
	TJSCannotGetResult.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_GET_RESULT]);
	TJSNullAccess.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NULL_ACCESS]);
	TJSMemberNotFound.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MEMBER_NOT_FOUND]);
	TJSMemberNotFoundNoNameGiven.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN]);
	TJSNotImplemented.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_IMPLEMENTED]);
	TJSInvalidParam.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_PARAM]);
	TJSBadParamCount.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_BAD_PARAM_COUNT]);
	TJSInvalidType.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_TYPE]);
	TJSSpecifyDicOrArray.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SPECIFY_DIC_OR_ARRAY]);
	TJSSpecifyArray.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SPECIFY_ARRAY]);
	TJSStringDeallocError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_STRING_DEALLOC_ERROR]);
	TJSStringAllocError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_STRING_ALLOC_ERROR]);
	TJSMisplacedBreakContinue.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MISPLACED_BREAK_CONTINUE]);
	TJSMisplacedCase.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MISPLACED_CASE]);
	TJSMisplacedReturn.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MISPLACED_RETURN]);
	TJSStringParseError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_STRING_PARSE_ERROR]);
	TJSNumberError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NUMBER_ERROR]);
	TJSUnclosedComment.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNCLOSED_COMMENT]);
	TJSInvalidChar.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_CHAR]);
	TJSExpected.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_EXPECTED]);
	TJSSyntaxError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SYNTAX_ERROR]);
	TJSPPError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_PPERROR]);
	TJSCannotGetSuper.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_GET_SUPER]);
	TJSInvalidOpecode.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_OPECODE]);
	TJSRangeError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_RANGE_ERROR]);
	TJSAccessDenyed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_ACCESS_DENYED]);
	TJSNativeClassCrash.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NATIVE_CLASS_CRASH]);
	TJSInvalidObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_OBJECT]);
	TJSCannotOmit.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_OMIT]);
	TJSCannotParseDate.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_PARSE_DATE]);
	TJSInvalidValueForTimestamp.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_VALUE_FOR_TIMESTAMP]);
	TJSExceptionNotFound.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_EXCEPTION_NOT_FOUND]);
	TJSInvalidFormatString.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_FORMAT_STRING]);
	TJSDivideByZero.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_DIVIDE_BY_ZERO]);
	TJSNotReconstructiveRandomizeData.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA]);
	TJSSymbol.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SYMBOL]);
	TJSCallHistoryIsFromOutOfTJS2Script.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT]);
	TJSNObjectsWasNotFreed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOBJECTS_WAS_NOT_FREED]);
#ifdef TJS_TEXT_OUT_CRLF
	TJSObjectCreationHistoryDelimiter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF]);
#else
	TJSObjectCreationHistoryDelimiter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_CREATION_HISTORY_DELIMITER]);
#endif
#ifdef TJS_TEXT_OUT_CRLF
	TJSObjectWasNotFreed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_WAS_NOT_FREED_CRLF]);
#else
	TJSObjectWasNotFreed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_WAS_NOT_FREED]);
#endif
	TJSGroupByObjectTypeAndHistory.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY]);
	TJSGroupByObjectType.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_GROUP_BY_OBJECT_TYPE]);
#ifdef TJS_TEXT_OUT_CRLF
	TJSObjectCountingMessageGroupByObjectTypeAndHistory.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF]);
#else
	TJSObjectCountingMessageGroupByObjectTypeAndHistory.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY]);
#endif
	TJSObjectCountingMessageTJSGroupByObjectType.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE]);
#ifdef TJS_TEXT_OUT_CRLF
	TJSWarnRunningCodeOnDeletingObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF]);
#else
	TJSWarnRunningCodeOnDeletingObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT]);
#endif
	TJSWriteError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WRITE_ERROR]);
	TJSReadError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_READ_ERROR]);
	TJSSeekError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SEEK_ERROR]);
	TJSByteCodeBroken.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_BYTE_CODE_BROKEN]);
	TJSObjectHashMapLogVersionMismatch.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH]);
	TJSCurruptedObjectHashMapLog.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG]);
	TJSUnknownFailure.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_FAILURE]);
	TJSUnknownPackUnpackTemplateCharcter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER]);
	TJSUnknownBitStringCharacter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_BIT_STRING_CHARACTER]);
	TJSUnknownHexStringCharacter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_HEX_STRING_CHARACTER]);
	TJSNotSupportedUuencode.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_UUENCODE]);
	TJSNotSupportedBER.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_BER]);
	TJSNotSupportedUnpackLP.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_UNPACK_LP]);
	TJSNotSupportedUnpackP.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_UNPACK_P]);
}
#endif
#if STATIC_CH|STATIC_JP|STATIC_EN
const tjs_char* RESOURCE_MESSAGE[] = {
	IDS_TJS_INTERNAL_ERROR,
	IDS_TJS_WARNING,
	IDS_TJS_WARN_EVAL_OPERATOR,
	IDS_TJS_NARROW_TO_WIDE_CONVERSION_ERROR,
	IDS_TJS_VARIANT_CONVERT_ERROR,
	IDS_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT,
	IDS_TJS_IDEXPECTED,
	IDS_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT,
	IDS_TJS_CANNOT_MODIFY_LHS,
	IDS_TJS_INSUFFICIENT_MEM,
	IDS_TJS_CANNOT_GET_RESULT,
	IDS_TJS_NULL_ACCESS,
	IDS_TJS_MEMBER_NOT_FOUND,
	IDS_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN,
	IDS_TJS_NOT_IMPLEMENTED,
	IDS_TJS_INVALID_PARAM,
	IDS_TJS_BAD_PARAM_COUNT,
	IDS_TJS_INVALID_TYPE,
	IDS_TJS_SPECIFY_DIC_OR_ARRAY,
	IDS_TJS_SPECIFY_ARRAY,
	IDS_TJS_STRING_DEALLOC_ERROR,
	IDS_TJS_STRING_ALLOC_ERROR,
	IDS_TJS_MISPLACED_BREAK_CONTINUE,
	IDS_TJS_MISPLACED_CASE,
	IDS_TJS_MISPLACED_RETURN,
	IDS_TJS_STRING_PARSE_ERROR,
	IDS_TJS_NUMBER_ERROR,
	IDS_TJS_UNCLOSED_COMMENT,
	IDS_TJS_INVALID_CHAR,
	IDS_TJS_EXPECTED,
	IDS_TJS_SYNTAX_ERROR,
	IDS_TJS_PPERROR,
	IDS_TJS_CANNOT_GET_SUPER,
	IDS_TJS_INVALID_OPECODE,
	IDS_TJS_RANGE_ERROR,
	IDS_TJS_ACCESS_DENYED,
	IDS_TJS_NATIVE_CLASS_CRASH,
	IDS_TJS_INVALID_OBJECT,
	IDS_TJS_CANNOT_OMIT,
	IDS_TJS_CANNOT_PARSE_DATE,
	IDS_TJS_INVALID_VALUE_FOR_TIMESTAMP,
	IDS_TJS_EXCEPTION_NOT_FOUND,
	IDS_TJS_INVALID_FORMAT_STRING,
	IDS_TJS_DIVIDE_BY_ZERO,
	IDS_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA,
	IDS_TJS_SYMBOL,
	IDS_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT,
	IDS_TJS_NOBJECTS_WAS_NOT_FREED,
	IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF,
	IDS_TJS_OBJECT_CREATION_HISTORY_DELIMITER,
	IDS_TJS_OBJECT_WAS_NOT_FREED_CRLF,
	IDS_TJS_OBJECT_WAS_NOT_FREED,
	IDS_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY,
	IDS_TJS_GROUP_BY_OBJECT_TYPE,
	IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF,
	IDS_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY,
	IDS_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE,
	IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF,
	IDS_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT,
	IDS_TJS_WRITE_ERROR,
	IDS_TJS_READ_ERROR,
	IDS_TJS_SEEK_ERROR,
	IDS_TJS_BYTE_CODE_BROKEN,
	IDS_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH,
	IDS_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG,
	IDS_TJS_UNKNOWN_FAILURE,
	IDS_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER,
	IDS_TJS_UNKNOWN_BIT_STRING_CHARACTER,
	IDS_TJS_UNKNOWN_HEX_STRING_CHARACTER,
	IDS_TJS_NOT_SUPPORTED_UUENCODE,
	IDS_TJS_NOT_SUPPORTED_BER,
	IDS_TJS_NOT_SUPPORTED_UNPACK_LP,
	IDS_TJS_NOT_SUPPORTED_UNPACK_P,
};
void TVPLoadMessage() {
	TJSInternalError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INTERNAL_ERROR]);
	TJSWarning.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARNING]);
	TJSWarnEvalOperator.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARN_EVAL_OPERATOR]);
	TJSNarrowToWideConversionError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NARROW_TO_WIDE_CONVERSION_ERROR]);
	TJSVariantConvertError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_VARIANT_CONVERT_ERROR]);
	TJSVariantConvertErrorToObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_VARIANT_CONVERT_ERROR_TO_OBJECT]);
	TJSIDExpected.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_IDEXPECTED]);
	TJSSubstitutionInBooleanContext.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SUBSTITUTION_IN_BOOLEAN_CONTEXT]);
	TJSCannotModifyLHS.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_MODIFY_LHS]);
	TJSInsufficientMem.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INSUFFICIENT_MEM]);
	TJSCannotGetResult.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_GET_RESULT]);
	TJSNullAccess.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NULL_ACCESS]);
	TJSMemberNotFound.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MEMBER_NOT_FOUND]);
	TJSMemberNotFoundNoNameGiven.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MEMBER_NOT_FOUND_NO_NAME_GIVEN]);
	TJSNotImplemented.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_IMPLEMENTED]);
	TJSInvalidParam.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_PARAM]);
	TJSBadParamCount.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_BAD_PARAM_COUNT]);
	TJSInvalidType.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_TYPE]);
	TJSSpecifyDicOrArray.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SPECIFY_DIC_OR_ARRAY]);
	TJSSpecifyArray.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SPECIFY_ARRAY]);
	TJSStringDeallocError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_STRING_DEALLOC_ERROR]);
	TJSStringAllocError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_STRING_ALLOC_ERROR]);
	TJSMisplacedBreakContinue.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MISPLACED_BREAK_CONTINUE]);
	TJSMisplacedCase.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MISPLACED_CASE]);
	TJSMisplacedReturn.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_MISPLACED_RETURN]);
	TJSStringParseError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_STRING_PARSE_ERROR]);
	TJSNumberError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NUMBER_ERROR]);
	TJSUnclosedComment.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNCLOSED_COMMENT]);
	TJSInvalidChar.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_CHAR]);
	TJSExpected.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_EXPECTED]);
	TJSSyntaxError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SYNTAX_ERROR]);
	TJSPPError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_PPERROR]);
	TJSCannotGetSuper.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_GET_SUPER]);
	TJSInvalidOpecode.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_OPECODE]);
	TJSRangeError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_RANGE_ERROR]);
	TJSAccessDenyed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_ACCESS_DENYED]);
	TJSNativeClassCrash.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NATIVE_CLASS_CRASH]);
	TJSInvalidObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_OBJECT]);
	TJSCannotOmit.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_OMIT]);
	TJSCannotParseDate.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CANNOT_PARSE_DATE]);
	TJSInvalidValueForTimestamp.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_VALUE_FOR_TIMESTAMP]);
	TJSExceptionNotFound.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_EXCEPTION_NOT_FOUND]);
	TJSInvalidFormatString.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_INVALID_FORMAT_STRING]);
	TJSDivideByZero.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_DIVIDE_BY_ZERO]);
	TJSNotReconstructiveRandomizeData.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_RECONSTRUCTIVE_RANDOMIZE_DATA]);
	TJSSymbol.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SYMBOL]);
	TJSCallHistoryIsFromOutOfTJS2Script.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CALL_HISTORY_IS_FROM_OUT_OF_TJS2SCRIPT]);
	TJSNObjectsWasNotFreed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOBJECTS_WAS_NOT_FREED]);
#ifdef TJS_TEXT_OUT_CRLF
	TJSObjectCreationHistoryDelimiter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_CREATION_HISTORY_DELIMITER_CRLF]);
#else
	TJSObjectCreationHistoryDelimiter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_CREATION_HISTORY_DELIMITER]);
#endif
#ifdef TJS_TEXT_OUT_CRLF
	TJSObjectWasNotFreed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_WAS_NOT_FREED_CRLF]);
#else
	TJSObjectWasNotFreed.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_WAS_NOT_FREED]);
#endif
	TJSGroupByObjectTypeAndHistory.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_GROUP_BY_OBJECT_TYPE_AND_HISTORY]);
	TJSGroupByObjectType.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_GROUP_BY_OBJECT_TYPE]);
#ifdef TJS_TEXT_OUT_CRLF
	TJSObjectCountingMessageGroupByObjectTypeAndHistory.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY_CRLF]);
#else
	TJSObjectCountingMessageGroupByObjectTypeAndHistory.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_COUNTING_MESSAGE_GROUP_BY_OBJECT_TYPE_AND_HISTORY]);
#endif
	TJSObjectCountingMessageTJSGroupByObjectType.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_COUNTING_MESSAGE_TJSGROUP_BY_OBJECT_TYPE]);
#ifdef TJS_TEXT_OUT_CRLF
	TJSWarnRunningCodeOnDeletingObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT_CRLF]);
#else
	TJSWarnRunningCodeOnDeletingObject.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WARN_RUNNING_CODE_ON_DELETING_OBJECT]);
#endif
	TJSWriteError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_WRITE_ERROR]);
	TJSReadError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_READ_ERROR]);
	TJSSeekError.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_SEEK_ERROR]);
	TJSByteCodeBroken.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_BYTE_CODE_BROKEN]);
	TJSObjectHashMapLogVersionMismatch.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_OBJECT_HASH_MAP_LOG_VERSION_MISMATCH]);
	TJSCurruptedObjectHashMapLog.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_CURRUPTED_OBJECT_HASH_MAP_LOG]);
	TJSUnknownFailure.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_FAILURE]);
	TJSUnknownPackUnpackTemplateCharcter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_PACK_UNPACK_TEMPLATE_CHARCTER]);
	TJSUnknownBitStringCharacter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_BIT_STRING_CHARACTER]);
	TJSUnknownHexStringCharacter.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_UNKNOWN_HEX_STRING_CHARACTER]);
	TJSNotSupportedUuencode.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_UUENCODE]);
	TJSNotSupportedBER.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_BER]);
	TJSNotSupportedUnpackLP.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_UNPACK_LP]);
	TJSNotSupportedUnpackP.AssignMessage(RESOURCE_MESSAGE[NUM_TJS_NOT_SUPPORTED_UNPACK_P]);
}
#endif
const tjs_char* TVPGetMessage(tjs_int id) {
	if (id >= 0 && id < NUM_MESSAGE_MAX) {
		return RESOURCE_MESSAGE[id];
	}
	else {
		return NULL;
	}
}
void TVPFreeMessages() {
	for (int i = 0; i < NUM_MESSAGE_MAX; i++) {
		delete[] RESOURCE_MESSAGE[i];
	}
}
}