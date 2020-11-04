#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	Mode_FadeNone,
	Mode_FadeIn,
	Mode_FadeOut
};

enum InputState {
	Input_Invalid = -2,
	Input_Released,
	Input_NotPressed,
	Input_Pressed
};

// マウスボタンの入力状態を調べる範囲
const int MOUSEBUTTON_UPDATE_RANGE = 5;

/// <summary>
/// フェード処理の中身
/// </summary>
/// <param name="fademode">フェードの種類</param>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードする色</param>
/// <param name="waitTime">フェードの待ち時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool Fade( FadeMode fademode, unsigned int fadePower, int fadeColor, int waitTime );

/// <summary>
/// フェードイン
/// </summary>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードインする前の色</param>
/// <param name="waitTime">フェードが始まる前に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeIn( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// フェードアウト
/// </summary>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードアウトした後の色</param>
/// <param name="waitTime">フェードが終わった後に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeOut( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// キーの入力状態を更新する
/// :毎フレーム呼び出す
/// </summary>
/// <returns>0以外はエラー</returns>
int UpdateKeyState();

/// <summary>
/// キーの入力状態を取得する
/// </summary>
/// <param name="keyCode">入力状態を取得したいキーのキーコード</param>
/// <returns>-1:離された 0:押されていない 1:押された 2以上:押されているフレーム数</returns>
int GetKeyStatus( int keyCode );

/// <summary>
/// キー入力の無効/有効切り替え
/// </summary>
/// <param name="keyCode">入力の無効/有効を切り替えたいキーのキーコード</param>
void KeyInputInvalidSwitching( int keyCode );

/// <summary>
/// マウスボタンの入力状態を更新する
/// :毎フレーム呼び出す
/// </summary>
/// <returns>0以外はエラー</returns>
int UpdateMouseButtonState();

/// <summary>
/// マウスボタンの入力状態を取得する
/// </summary>
/// <param name="mouseButtonCode">入力状態を取得したいマウスボタンのコード</param>
/// <returns></returns>
int GetMouseButtonStatus( int mouseButtonCode );

/// <summary>
/// マウスボタン入力の無効/有効切り替え
/// </summary>
/// <param name="keyCode">入力の無効/有効を切り替えたいマウスボタンのコード</param>
void MouseButtonInputInvalidSwitching( int mouseButtonCode );

#endif // !FUNCTION_H
