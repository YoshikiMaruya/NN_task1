//ex1-2.cpp
//パーセプトロンによる論理回路の学習
#include <iostream>
using namespace std;
int formal_neuron(int x[], double weight[], double b, int n){
  //演習 1 と同様に定義
  double sum = 0;
  //sum に x[i]*weight[i]を n 個分合計する
  for(int i=0;i<n;i++){
    sum += x[i] * weight[i];
  }
  //sum に b を追加する
  sum += b;
  //sum>0 ならば 1 を、そうでなければ 0 を return する
  if(sum > 0) return 1;
  else return 0;
}
int main() {
  int x[4][2] = {{0,0},{0,1},{1,0},{1,1}}; //入力ニューロンのデータ
  int y; //出力ニューロンの値
  int n = 2; //入力ニューロンの数
  double w[2] = {}; //重みを全て 0 に初期設定
  double b = 0; //切片を全て 0 に初期設定
  int t[4] = {0,1,1,1}; //教師データの設定
  double lambda = 0.1; //学習のステップサイズの設定
  //パーセプトロンの学習
  int count; //出力ニューロンと教師データが同一でなかった回数
  do{
    count = 0;
    for(int p = 0; p < 4; p++){
      y = formal_neuron(x[p],w,b,n);
      if(t[p] != y){
 count++; //出力と教師が同一でなかった回数を数える
 for(int i = 0; i < n; i++){
   //w[i]の値に lambda*(t[p] - y)*x[p][i]を加えて更新
   w[i] += lambda * (t[p] - y) * x[p][i];
 }
 //b の値を lambda*(t[p] - y)を加えて更新
 b += lambda * (t[p] - y);
      }
    }
  }while(count);       //出力ニューロンと教師データが完全に一致するまで繰り返す
  //結果の表示
  for(int p = 0; p < 4; p++){
    cout << "x:";
    for(int i = 0; i < n; i++){
      cout << x[p][i];
    }
    y = formal_neuron(x[p],w,b,n);
    cout << " y:" << y << endl;
  }
  //学習された重みと切片の表示
  cout << "w:";
  for(int i = 0; i < n; i++){
    cout << w[i] << " ";
  }
  cout << "b:"; cout << b << endl;
  return 0;
}