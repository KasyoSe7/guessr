#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // 乱数の初期化
    int answer; // 答え
    int guess;  //プレーヤー答え
    int attempts = 0;   //答えた回数
    int minVal, maxVal; //最小値、最大値
    string name;    //プレイヤーネーム
    string playAgain;
    cout << "あなたの名前を入力してください：";
    cin >> name;
    
    do {
        attempts = 0;
        cout << "最小の値を入力してください：";
        cin >> minVal;
        cout << "最大の値を入力してください：";
        cin >> maxVal;

        // 入力チェック（必要に応じて）
        if (minVal >= maxVal) {
            cout << "範囲が正しくないので、入れ替えます。" << endl;
            swap(minVal, maxVal);
        }
        answer = rand() % (maxVal - minVal + 1) + minVal;
        cout << "☆ 数当てゲーム（" << minVal << "～" << maxVal << ")☆" << endl;
        while (attempts < 10) {
            cout << "数字を入力してください：";
            cin >> guess;
            attempts++;

            if (guess < answer) {
                cout << "もっと大きいよ！" << endl;
            }
            else if (guess > answer) {
                cout << "もっと小さいよ！" << endl;
            }
            else {
                cout << name << "さん、正解！ " << attempts << "回で当たったよ！" << endl;
                break;
            }
        }
        if (guess != answer) {
            cout << "gameover 答え:" << answer << endl;
        }
        cout << "もう一度遊ぶ？(YES/NO)" << endl;
        cin >> playAgain;
        if (playAgain == "NO") {
            break;
        }

        cout << "Enterキーで次へ進む...";
        cin.ignore();
        cin.get();
        system("cls");  // 画面クリア
    } while (playAgain == "YES");
}
