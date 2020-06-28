// ex1-3.cpp
//パーセプトロンによる論理回路の学習
#include <iostream>
using namespace std;
int formal_neuron(int x[], double weight[], double b, int n) {
 double sum = 0;
 //sumにx[i]*weight[i]をn個分合計する
 for (int i = 0; i < n; i++) {
  sum += (x[i] * weight[i]);
 }
 //sumにbを追加する
 sum += b;
 //sum>0ならば1を、そうでなければ0をreturnする
 if (sum > 0)return 1;
 else return 0;
}
int main() {
 int x[4][4] = { {0,0,0,1},{0,0,1,0},{0,1,0,0},{1,0,0,0} }; //入力ニューロンのデータ
 int y[2]; //出力ニューロンの値
 int n = 4; //入力ニューロンの数
 int m = 2; //出力ニューロンの数
 double w[2][4] = {}; //重みを全て0に初期設定
 double b[2] = {}; //切片を全て0に初期設定
 int t[4][2] = { {0,0},{0,1},{1,0},{1,1} }; //教師データの設定
 double lambda = 0.1; //学習のステップサイズの設定
 //パーセプトロンの学習
 int count; //出力ニューロンと教師データが同一でなかった回数
 do {
  count = 0;
  for (int p = 0; p < 4; p++) {
   for (int q = 0; q < m; q++) {
    y[q] = formal_neuron(x[p], w[q], b[q], n);
    if (t[p][q] != y[q]) {
     count++; //出力と教師が同一でなかった回数を数える
     for (int i = 0; i < n; i++) {
      //w[i]の値にlambda*(t[p] - y)*x[p][i]を加えて更新
      w[q][i] += (lambda * (t[p][q] - y[q]) * x[p][i]);
     }
     //bの値をlambda*(t[p] - y)を加えて更新
     b[q] += (lambda * (t[p][q] - y[q]));
    }
   }
  }
 } while (count); //出力ニューロンと教師データが完全に一致するまで繰り返す
 //結果の表示
 for (int p = 0; p < 4; p++) {
  cout << "x:";
  for (int i = 0; i < n; i++) {
   cout << x[p][i];
  }
  for (int q = 0; q < m; q++) {
   y[q] = formal_neuron(x[p], w[q], b[q], n);
   if (q == 0) cout << " y:" << y[q];
   else cout << y[q] << endl;
  }
 }
 //学習された重みと切片の表示
 for (int q = 0; q < m; q++) {
  cout << "y" << q << " ";
  cout << "w:";
  for (int i = 0; i < n; i++) {
   cout << w[q][i] << " ";
  }
  cout << "b:"; cout << b[q] << endl;
 }
 return 0;
}