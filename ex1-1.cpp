//ex1-1.cpp
//形式ニューロンによる論理回路
#include <iostream>
using namespace std;
//形式ニューロンの出力の計算
int formal_neuron(int x[], double weight[], double b, int n){
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
  double w[2] = {0.5,0.5}; //重みの設定
  double b = 0; //切片の設定
  //ニューロンの値の計算と表示
  for(int p = 0; p < 4; p++){
    // p 番目のデータの各入力ニューロンの値の表示
    cout << "x:";
    for(int i = 0; i < n; i++){
      cout << x[p][i]; }
    //p 番目の入力データに対する形式ニューロンの値の計算
    y = formal_neuron(x[p],w,b,n);
    cout << " y:" << y << endl; }
  return 0;
}