#include <iostream>
#include <vector>
#include <string>
using namespace std;

//penyertaan file header anak.h dan ibu.h
#include "anak.h"
#include "ibu.h"

int main()
{
    //deklarasi dan pemberian nilai variabel pointer untuk objek dari class ibu dan anak
    Ibu* varIbu = new Ibu("rani");
    Ibu* varIbu2 = new Ibu("sari");
    anak* varAnak1 = new anak("tono");
    anak* varAnak2 = new anak("tiara");
    anak* varAnak3 = new anak("dini");

