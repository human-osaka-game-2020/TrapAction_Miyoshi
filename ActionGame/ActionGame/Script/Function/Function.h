﻿
#ifndef FUNCTION_H
#define FUNCTION_H

#include "../Common.h"

// フェードの状態
enum class FadeMode {
	None,	// フェードなし
	In,	// フェードイン中
	Out	// フェードアウト中
};

// キーボード、マウスの入力状態
enum class InputState {
	NotPressed,		// 押されていない
	Pressed,		// 押された瞬間
	Pressing,		// 押している
	Released,		// 離した瞬間
	Invalid			// 無効
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

/// @brief すべてのキーで現在押されているかを調べる
/// @param stateArray 情報保存用のbool配列
void CheckKeyPushed( bool* pStateArray );

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
/// <returns>InputStateで返す</returns>
InputState GetKeyStatus( int keyCode );

/// <summary>
/// キー入力の無効/有効切り替え
/// </summary>
/// <param name="keyCode">入力の無効/有効を切り替えたいキーのキーコード</param>
void SwitchEnabledKeyInput( int keyCode );

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
/// <returns>InputStateで返す</returns>
InputState GetMouseButtonStatus( int mouseButtonCode );

/// <summary>
/// マウスボタン入力の無効/有効切り替え
/// </summary>
/// <param name="keyCode">入力の無効/有効を切り替えたいマウスボタンのコード</param>
void SwitchEnabledMouseButtonInput( int mouseButtonCode );

/// @brief 画面外か調べる
/// @param data キャラクターデータ
/// @param checkRoof 天井を判定するか
/// @return 画面外ならtrue
bool CheckOffWindow( CharacterData data, bool checkRoof = true );

#endif // !FUNCTION_H
