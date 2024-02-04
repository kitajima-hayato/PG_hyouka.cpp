#include <Novice.h>
#include"Player.h"
const char kWindowTitle[] = "キタジマ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1000, 700);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	int bg[3] = {
		Novice::LoadTexture("./image/title.png"),
		Novice::LoadTexture("./image/bg.png"),
		Novice::LoadTexture("./image/result.png"),
	};
	enum Scene {
		TITLE,GAME,RESULT
	};
	Scene scene = TITLE;
	Player* player = new Player;
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (scene)
		{
		case TITLE:
			Novice::DrawSprite(0, 0, bg[0], 1, 1, 0, WHITE);
			player->Reboot();
			if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE]) { scene = GAME; }
			break;
		case GAME:
			Novice::DrawSprite(0, 0, bg[1], 1, 1, 0, WHITE);
			//更新↓
			player->Init(keys, preKeys);
			if (player->enemy_->Getlife() == 3) { scene = RESULT; }
			//描画↓
			player->Draw();
			break;
		case RESULT:
			Novice::DrawSprite(0, 0, bg[2], 1, 1, 0, WHITE);
			if (preKeys[DIK_SPACE]==0&&keys[DIK_SPACE]) { scene = TITLE; }
			break;
		}
		
		
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	delete player;
	//delete enemy;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
