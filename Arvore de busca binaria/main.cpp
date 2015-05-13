/* teste.cpp: teste de �rvores bin�rias de busca */
#include <cstdlib>
#include <iostream>
#include "arv_bb.h"

using namespace std;  /* Necess�rio no Visual C++ 7.0 */


int main(void){
    
    arv_bb a;
    
    a.ins(20);
    a.ins(10);
    a.ins(30);
    a.ins(8);
    a.ins(15);
    a.ins(6);
    a.ins(14);
    a.ins(35);
    a.ins(29);
    a.ins(25);
    a.ins(33);
    a.ins(8);
    a.ins(7);
    a.ins(8);
    a.mostra();
    a.altura();
//    
//    if (a.busca(15))
//        cout << "15 esta presente" << endl;
//    else
//        cout << "15 nao esta presente" << endl;
//    if (a.busca(16))
//        cout << "16 esta presente" << endl;
//    else
//    {
//        cout << "16 nao esta presente" << endl;
//    };
//    
//    a.rem(10);
//    a.mostra();
//    a.rem(14);
//    a.rem(15);
//    a.mostra();
//    
//    a.rem(18);
//    a.rem(6);
//    a.rem(40);
//    a.rem(9);
//    a.rem(30);
//    
//    a.mostra();
//    
//    a.rem(8);
//    a.rem(20);
//    a.rem(25);
//    a.rem(33);
//    
//    a.mostra();
//    
    system("PAUSE");
    return 0;
}