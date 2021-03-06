﻿
#ifndef SC_TITLE_H
#define SC_TITLE_H

#include "../Common.h"
#include "../Function/Function.h"
#include "SceneBase.h"

// タイトルシーン
class TitleScene : public SceneBase {
public:
	// コンストラクタ
	TitleScene();

	// デストラクタ
	~TitleScene();

	// メインループで呼び出すもの
	void Execute();

private:
	// ゲーム処理
	// Execute内で呼び出し
	void Control();

	// 描画処理
	// Execute内で呼び出し
	void Draw();

	bool SelectMenu();

	int currentSelect;
	int pointerRadius;

	enum Menu{
		NewGame_m,	// 最初から
		Continue_m,	// つづきから

		MenuMax
	};
};

#endif
