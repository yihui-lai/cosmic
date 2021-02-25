
#include "Plotter/langaus.C"

void fit_langaus(){
//root/Cosmics/Fingertile_27Jan2021_tile9_5cm_001.root
    char fname[60];
    sprintf(fname, "root/Cosmics/Fingertile_14Feb2021_tile11_8p25cm_hole_open_001_yh.root", 1);
    //sprintf(fname, "root/Cosmics/Fingertile_27Jan2021_tile10_1cm_001.root", 1);
    
    cout<<"open "<<fname<<endl;
    TChain* fchain=new TChain("tree");
    fchain->Add(fname);
    fchain->Draw("areaFromScope*-1.e9>>(200,-2,10)");
    
    cout<<"fit range: "<<endl;
    double fitmin_,fitmax_;
    double pedmin_,pedmax_;
    fitmin_=-2;
    fitmax_=10;
    pedmin_=-1.5;
    pedmax_=-0.75;
    double fitRng[] = {8,fitmin_,fitmax_};
    double fitRngPed[] = {10,pedmin_,pedmax_};
    
    PyLandGaus *fobj=new PyLandGaus();
    fobj->langaus(fname,fitRng,true,fitRngPed);
    

}

