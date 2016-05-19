#include <iostream>

using namespace std;

void perform_cnt(int i, long long int *cnt) {
    while (i) {
        cnt[i % 10]++;
        i /= 10;
    }
}

long long int precalc[80][10] = {
        {0,         0,         0,         0,         0,         0,         0,         0,         0,         0},
        {8438894,   12050001,  9050001,   8550000,   8550000,   8450001,   8450000,   8450000,   8450000,   8450000},
        {16888895,  28000000,  23000001,  18000000,  18000000,  17000001,  17000000,  17000000,  17000000,  17000000},
        {25438894,  36550000,  36550000,  34050001,  26550000,  26450001,  26450000,  25950001,  25450000,  25450000},
        {33888896,  45000000,  45000000,  45000000,  45000000,  35000001,  35000000,  35000000,  35000000,  35000000},
        {43438894,  54550000,  54050001,  53550000,  53550000,  53450001,  45950001,  43450000,  43450000,  43450000},
        {51888895,  63000000,  63000000,  63000000,  63000000,  62000001,  62000000,  57000001,  52000000,  52000000},
        {60438894,  71550000,  71550000,  71550000,  71550000,  71450001,  71450000,  70950001,  67950001,  60450000},
        {68888897,  80000001,  80000000,  80000000,  80000000,  80000000,  80000000,  80000000,  80000000,  80000000},
        {88438894,  104550002, 89050001,  88550000,  88550000,  88450001,  88450000,  88450000,  88450000,  88450000},
        {96888895,  133000001, 103000001, 98000000,  98000000,  97000001,  97000000,  97000000,  97000000,  97000000},
        {105438894, 154050001, 116550000, 114050001, 106550000, 106450001, 106450000, 105950001, 105450000, 105450000},
        {113888896, 175000001, 125000000, 125000000, 125000000, 115000001, 115000000, 115000000, 115000000, 115000000},
        {123438894, 197050001, 134050001, 133550000, 133550000, 133450001, 125950001, 123450000, 123450000, 123450000},
        {131888895, 218000001, 143000000, 143000000, 143000000, 142000001, 142000000, 137000001, 132000000, 132000000},
        {140438894, 239050001, 151550000, 151550000, 151550000, 151450001, 151450000, 150950001, 147950001, 140450000},
        {148888897, 260000000, 160000001, 160000000, 160000000, 160000000, 160000000, 160000000, 160000000, 160000000},
        {168438894, 272050001, 181550002, 168550000, 168550000, 168450001, 168450000, 168450000, 168450000, 168450000},
        {176888895, 288000000, 208000002, 178000000, 178000000, 177000001, 177000000, 177000000, 177000000, 177000000},
        {185438894, 296550000, 234050001, 194050001, 186550000, 186450001, 186450000, 185950001, 185450000, 185450000},
        {193888896, 305000000, 255000001, 205000000, 205000000, 195000001, 195000000, 195000000, 195000000, 195000000},
        {203438894, 314550000, 276550002, 213550000, 213550000, 213450001, 205950001, 203450000, 203450000, 203450000},
        {211888895, 323000000, 298000001, 223000000, 223000000, 222000001, 222000000, 217000001, 212000000, 212000000},
        {220438894, 331550000, 319050001, 231550000, 231550000, 231450001, 231450000, 230950001, 227950001, 220450000},
        {228888897, 340000000, 340000000, 240000001, 240000000, 240000000, 240000000, 240000000, 240000000, 240000000},
        {248438894, 352050001, 349050001, 261050001, 248550000, 248450001, 248450000, 248450000, 248450000, 248450000},
        {256888895, 368000000, 363000001, 283000001, 258000000, 257000001, 257000000, 257000000, 257000000, 257000000},
        {265438894, 376550000, 376550000, 311550002, 266550000, 266450001, 266450000, 265950001, 265450000, 265450000},
        {273888896, 385000000, 385000000, 335000001, 285000000, 275000001, 275000000, 275000000, 275000000, 275000000},
        {283438894, 394550000, 394050001, 356050001, 293550000, 293450001, 285950001, 283450000, 283450000, 283450000},
        {291888895, 403000000, 403000000, 378000001, 303000000, 302000001, 302000000, 297000001, 292000000, 292000000},
        {300438894, 411550000, 411550000, 399050001, 311550000, 311450001, 311450000, 310950001, 307950001, 300450000},
        {308888897, 420000000, 420000000, 420000000, 320000001, 320000000, 320000000, 320000000, 320000000, 320000000},
        {328438894, 432050001, 429050001, 428550000, 341050001, 328450001, 328450000, 328450000, 328450000, 328450000},
        {336888895, 448000000, 443000001, 438000000, 363000001, 337000001, 337000000, 337000000, 337000000, 337000000},
        {345438894, 456550000, 456550000, 454050001, 384050001, 346450001, 346450000, 345950001, 345450000, 345450000},
        {353888896, 465000000, 465000000, 465000000, 415000001, 355000001, 355000000, 355000000, 355000000, 355000000},
        {363438894, 474550000, 474050001, 473550000, 436050001, 373450001, 365950001, 363450000, 363450000, 363450000},
        {371888895, 483000000, 483000000, 483000000, 458000001, 382000001, 382000000, 377000001, 372000000, 372000000},
        {380438894, 491550000, 491550000, 491550000, 479050001, 391450001, 391450000, 390950001, 387950001, 380450000},
        {388888897, 500000000, 500000000, 500000000, 500000000, 400000001, 400000000, 400000000, 400000000, 400000000},
        {408438894, 512050001, 509050001, 508550000, 508550000, 420950002, 408450000, 408450000, 408450000, 408450000},
        {416888895, 528000000, 523000001, 518000000, 518000000, 442000002, 417000000, 417000000, 417000000, 417000000},
        {425438894, 536550000, 536550000, 534050001, 526550000, 463950002, 426450000, 425950001, 425450000, 425450000},
        {433888896, 545000000, 545000000, 545000000, 545000000, 485000002, 435000000, 435000000, 435000000, 435000000},
        {443438894, 554550000, 554050001, 553550000, 553550000, 515950002, 445950001, 443450000, 443450000, 443450000},
        {451888895, 563000000, 563000000, 563000000, 563000000, 537000002, 462000000, 457000001, 452000000, 452000000},
        {460438894, 571550000, 571550000, 571550000, 571550000, 558950002, 471450000, 470950001, 467950001, 460450000},
        {468888897, 580000000, 580000000, 580000000, 580000000, 580000000, 480000001, 480000000, 480000000, 480000000},
        {488438894, 592050001, 589050001, 588550000, 588550000, 588450001, 500950001, 488450000, 488450000, 488450000},
        {496888895, 608000000, 603000001, 598000000, 598000000, 597000001, 522000001, 497000000, 497000000, 497000000},
        {505438894, 616550000, 616550000, 614050001, 606550000, 606450001, 543950001, 505950001, 505450000, 505450000},
        {513888896, 625000000, 625000000, 625000000, 625000000, 615000001, 565000001, 515000000, 515000000, 515000000},
        {523438894, 634550000, 634050001, 633550000, 633550000, 633450001, 588450002, 523450000, 523450000, 523450000},
        {531888895, 643000000, 643000000, 643000000, 643000000, 642000001, 617000001, 537000001, 532000000, 532000000},
        {540438894, 651550000, 651550000, 651550000, 651550000, 651450001, 638950001, 550950001, 547950001, 540450000},
        {548888897, 660000000, 660000000, 660000000, 660000000, 660000000, 660000000, 560000001, 560000000, 560000000},
        {568438894, 672050001, 669050001, 668550000, 668550000, 668450001, 668450000, 580950001, 568450000, 568450000},
        {576888895, 688000000, 683000001, 678000000, 678000000, 677000001, 677000000, 602000001, 577000000, 577000000},
        {585438894, 696550000, 696550000, 694050001, 686550000, 686450001, 686450000, 623450002, 585450000, 585450000},
        {593888896, 705000000, 705000000, 705000000, 705000000, 695000001, 695000000, 645000001, 595000000, 595000000},
        {603438894, 714550000, 714050001, 713550000, 713550000, 713450001, 705950001, 665950001, 603450000, 603450000},
        {611888895, 723000000, 723000000, 723000000, 723000000, 722000001, 722000000, 692000002, 612000000, 612000000},
        {620438894, 731550000, 731550000, 731550000, 731550000, 731450001, 731450000, 718450002, 627950001, 620450000},
        {628888897, 740000000, 740000000, 740000000, 740000000, 740000000, 740000000, 740000000, 640000001, 640000000},
        {648438894, 752050001, 749050001, 748550000, 748550000, 748450001, 748450000, 748450000, 660950001, 648450000},
        {656888895, 768000000, 763000001, 758000000, 758000000, 757000001, 757000000, 757000000, 682000001, 657000000},
        {665438894, 776550000, 776550000, 774050001, 766550000, 766450001, 766450000, 765950001, 702950001, 665450000},
        {673888896, 785000000, 785000000, 785000000, 785000000, 775000001, 775000000, 775000000, 725000001, 675000000},
        {683438894, 794550000, 794050001, 793550000, 793550000, 793450001, 785950001, 783450000, 745950001, 683450000},
        {691888895, 803000000, 803000000, 803000000, 803000000, 802000001, 802000000, 797000001, 767000001, 692000000},
        {700438894, 811550000, 811550000, 811550000, 811550000, 811450001, 811450000, 810950001, 795450002, 700450000},
        {708888897, 820000000, 820000000, 820000000, 820000000, 820000000, 820000000, 820000000, 820000000, 720000001},
        {728438894, 832050001, 829050001, 828550000, 828550000, 828450001, 828450000, 828450000, 828450000, 740950001},
        {736888895, 848000000, 843000001, 838000000, 838000000, 837000001, 837000000, 837000000, 837000000, 762000001},
        {745438894, 856550000, 856550000, 854050001, 846550000, 846450001, 846450000, 845950001, 845450000, 782950001},
        {753888896, 865000000, 865000000, 865000000, 865000000, 855000001, 855000000, 855000000, 855000000, 805000001},
        {763438894, 874550000, 874050001, 873550000, 873550000, 873450001, 865950001, 863450000, 863450000, 825950001},
        {771888895, 883000000, 883000000, 883000000, 883000000, 882000001, 882000000, 877000001, 872000000, 847000001},
        {780438894, 891550000, 891550000, 891550000, 891550000, 891450001, 891450000, 890950001, 887950001, 867950001},
};

int main() {
    int n;
    cin >> n;
    long long int *cnt = precalc[n / 12500000];
    for (int i = 1 + 12500000 * (n / 12500000); i <= n; i++) {
        perform_cnt(i, cnt);
    }
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}