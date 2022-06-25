#include <stdio.h>
#include <stdlib.h>
int main(){
    int ANA=0,SLE=0;
    int hem=0,neu=0,muc=0,ser=0,mus=0,ren=0,pho=0,pro=0,santi=0;
    char x[5];
    printf("----Welcome to SLE diagnosis assistant!----\n");
    printf("Here comes entry criteron.\n");
    printf("ANA at a titer of 1:\"?\" on HEp-2 cells.");
    scanf("%d", &ANA);
    if(ANA<=80){
        printf("Additive criteria are needed before final diagnosis.\nThe following are some important conditions in clinical or immunological domains.\nPlease input \" Y \" if a patient meets the condition while input \" N \" if one doesn't.\nFirst, we need to know the patient's clinical conditions through the following questionaire.\n");
        for (int k = 1; k < 25;k++){
            switch(k){
            //Clinical domains and criteria
                //Constitutional 
                case 1:
                    printf("1. Questions about Constitutional domain:\nFever ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        SLE = SLE + 2;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else
                    { //防呆裝置 填Y、N、y、n以外的重跑一次case
                        printf("input \" Y \" or \" N \" only,try again.\n");
                        k = k - 1;
                    }
                    break;
                //Hematologic
                case 2:
                    printf("2. Questions about Hematologic domain:\nLeukopenia ?\nPlease input \" Y \" or \" N \".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        hem = 3;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 3:
                    printf("Thrombocytopenia ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(hem<4){
                            hem = 4;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 4:
                    printf("Autoimmune hemolysis ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(hem<4){
                            hem = 4;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + hem;
                    break;
                //Neuropsychiatric
                case 5:
                    printf("3. Questions about Neuropsychiatric domain:\nDelirium ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        neu = 2;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 6:
                    printf("Psychosis ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(neu<3){
                            neu = 3;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 7:
                    printf("Siezure ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(neu<5){
                            neu = 5;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + neu;
                    break;
                //Mucocutaneous
                case 8:
                    printf("4. Questions about Mucocutaneous domain:\nNon-scarring alopecia ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        muc = 2;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 9:
                    printf("Oral ulcers ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        muc = 2;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 10:
                    printf("Subacute cutaneous OR discoid lupus ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(muc<4){
                            muc = 4;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 11:
                    printf("Acute cutaneous lupus ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(muc<6){
                            muc = 6;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + muc;
                    break;
                //Serosal
                case 12:
                    printf("5. Questions about Serosal domain:\nPleural or pericardial effusion ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        ser = 5;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 13:
                    printf("Acute pericarditis ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(ser<6){
                            ser = 6;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + ser;
                    break;
                //Musculoskeletal
                case 14:
                    printf("6. Questions about Musculoskeletal domain:\nJoint involvment ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(mus<6){
                            mus = 6;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + mus;
                    break;
                //Renal
                case 15:
                    printf("7. Questions about Renal domain:\nProteinuria > 0.5g/24h ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        ren = 4;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 16:
                    printf("Renal biopsy Class II or V lupus nephritis ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(ren<8){
                            ren = 8;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 17:
                    printf("Renal biopsy Class III or IV lupus nephritis ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(ren<10){
                            ren = 10;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + ren;
                    break;
            //Immunology domains and criteria
                case 18:
                    printf("Then, we would like to further understand the patient's immunological conditions through the following questionaire.\n");
                    break;
                //Antiphospholipid antibodies
                case 19:
                    printf("1. Questions about Antiphospholipid_antibodies domain:\nAnti-cardiolipin antibodies OR Anti-B2GP1 antibodes OR Lupus anticoagulant ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        pho = 2;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + pho;
                    break;
                //Complement proteins
                case 20:
                    printf("2. Questions about Complement_proteins domain:\nLow C3 OR low C4 ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        pro = 3;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    break;
                case 21:
                    printf("Low C3 AND low C4 ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        if(pro<4){
                            pro = 4;
                        }
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + pro;
                    break;
                //SLE-specific antibodies
                case 22:
                    printf("3. Questions about SLE_specific_antibodies domain:\nAnti-dsDNA antibody OR Anti-Smith antibody ?\nPlease input \"Y\" or \"N\".");
                    scanf("\n%c", &x);
                    if(x[0]=='Y' || x[0]=='y'){
                        santi = 6;
                    }
                    else if(x[0]=='N' || x[0]=='n'){
                    }
                    else{
                        printf("input \" Y \" or \" N \" only,try again.");
                        k = k - 1;
                    }
                    SLE = SLE + santi;
                    break;
            }
        }
    }
    printf("Diagnostic result:\n");
    printf("Based on the 2019 EULAR/ACR classification criteria for SLE\n");
    if(SLE>=10){
        printf("This patient is classified as SLE,the total weights add up to %d pts.\n",SLE);
    }
    else if(SLE==0){ 
        printf("This patient is not classified as SLE.\n");
    }
    else{
        printf("This patient is not classified as SLE\nThe total weights add up to only %d pts, which doesn't reach the standard 10 pts for SLE diagnosis.\n",SLE);
    }
    return 0;
}