#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <limits.h>
int main(){
    int ANA=INT_MAX,b=0,c=0,ans=0,flag=0,SLE=0,point=0,t=0,q=0,cscore,imscore,bigdomain,bigillness,domainflag=0,bigpoint=0,domainnum=0;
    float percent;
    char cdomain[50][50] = { {"Constitutional"}, {"Hematologic"},{"Neuropsychiatric"},{"Mucocutaneous"},{"Serosal"},{"Musculoskeletal"},{"Renal"} };
    char imdomain[50][50] = { {"Antiphospholipid antibodies"},{"Complement proteins"},{"SLE-specific antibodies"} };
    char cillness[50][50] = { {"Fever"},{"x"},{"Leukopenia"},{"Thrombocytopenia"},{"Autoimmune hemolysis"},{"x"},{"Delirium"},{"Psychosis"},{"Siezure"},{"x"},{"Non-scarring alopecia"},{"Oral ulcers"},{"Subacute cutaneous OR discoid lupus"},{"Acute cutaneous lupus"},{"x"},{"Pleural or pericardial effusion"},{"Acute pericarditis"},{"x"},{"Joint involvment"},{"x"},{"Proteinuria > 0.5g/24h"},{"Renal biopsy Class II or V lupus nephritis"},{"Renal biopsy Class III or IV lupus nephritis"},{"x"} };
    char imillness[50][100] = { {"Anti-cardiolipin antibodies OR Anti-B2GP1 antibodes OR Lupus anticoagulant"},{"x"},{"Low C3 OR low C4"},{"Low C3 AND low C4"},{"x"},{"Anti-dsDNA antibody OR Anti-Smith antibody"},{"x"} };
    int cweight[50] = {2, 3, 4, 4, 2, 3, 5, 2, 2, 4, 6, 5, 6, 6, 4, 8, 10};
    int imweight[50] = {2, 3, 4, 6};
    int answer[50];
    char x;
    printf("----Welcome to SLE diagnosis assistant!----\n");
//data input
    printf("Here comes entry criteron.\n");
    do
    {
        printf("ANA at a titer of 1:\"?\" on HEp-2 cells.");
        scanf("%d", &ANA);
        if(ANA==INT_MAX){
            printf("You should not input characters, please input a positive number.\n");
            fflush(stdin);
        }
        else if(!(ANA>0)){
            printf("You should input a \"positive\" number.\n");
        }
    } while ( !(ANA>0) || ANA==INT_MAX );
    
    if(ANA<80 && ANA>0){
        printf("Additive criteria are needed before final diagnosis.\nThe following are some important conditions in clinical or immunological domains.\nPlease input \" Y \" if a patient meets the condition while input \" N \" if one doesn't.\n");       
        //Clinical domains and criteria
        printf("First, we need to know the patient's clinical conditions through the following questionaire.\n");
        for (int a = 1; a < 8;a++){
            printf("%d. Questions about %s domain:\n", a, cdomain[a - 1]);
            for (; b < 24;b++){
                if(cillness[b][0]=='x'){
                    b++;
                    break;
                }
                printf("%s ?\nPlease input \"Y\" or \"N\", input \"B\" can back to previous question. ", cillness[b]);
                scanf(" %c", &x);
                switch(toupper(x)){
                    case 'Y':
                        answer[ans] = 1, ans++;
                        flag = 1;
                        break;
                    case 'N':
                        answer[ans] = 0, ans++;
                        break;
                    case 'B':
                        b = b - 2;
                        if(b<-1){
                            b++;
                        }
                        else if(cillness[b+1][0]=='x'){
                            b = b - 1;
                            a = a - 1;
                        }
                        break;
                    default:
                        printf("input \" Y \" or \" N \" only,try again.\n");
                        b = b - 1;
                        break;
                }
            }
        }
        // Immunology domains and criteria
        printf("Then, we would like to further understand the patient's immunological conditions through the following questionaire\n");
        for (int a = 1; a < 4;a++){
            printf("%d. Questions about %s domain:\n", a, imdomain[a - 1]);
            for ( ; c < 7;c++){
                if(imillness[c][0]=='x'){
                    c++;
                    break;
                }
                printf("%s ?\nPlease input \"Y\" or \"N\", input \"B\" can back to previous question. ", imillness[c]);
                scanf(" %c", &x);
                switch(toupper(x)){
                    case 'Y':
                        answer[ans] = 1, ans++;
                        break;
                    case 'N':
                        answer[ans] = 0, ans++;
                        break;
                    case 'B':
                        c = c - 2;
                        if(c<-1){
                            c++;
                        }
                        else if(imillness[c+1][0]=='x'){
                            c = c - 1;
                            a = a - 1;
                        }
                        break;
                    default:
                        printf("input \" Y \" or \" N \" only,try again.\n");
                        c = c - 1;
                        break;
                }
            }
        }
        //data processing
        for ( int x=0; x < 24;x++){
            if(cillness[x][0]=='x'){
                SLE = SLE + point;
                point = 0,domainnum++;
                continue;
            }
            if(point<=cweight[t]*answer[t]){
                point = cweight[t]*answer[t];
                if(bigpoint<=point){
                    bigpoint = point, bigdomain=domainnum, bigillness=x;
                }
            }
            t++;
        }
        point = 0,domainnum=0,cscore=SLE;
        for ( int x=0; x < 7;x++){
            if(imillness[x][0]=='x'){
                SLE = SLE + point;
                point = 0,domainnum++;
                continue;
            }
            if(point<imweight[q]*answer[t]){
                point = imweight[q]*answer[t];
                if(bigpoint<=point){
                    bigpoint = point, bigdomain=domainnum, bigillness=x,domainflag=1;
                }
            }
            t++,q++;
        }
        imscore = SLE - cscore,percent=(float)bigpoint/SLE*100;
        //data output
        printf("\n\nThe total point of clinical score: %d pts\nThe total point of immunological score: %d pts\nThe total score is %d pts.\n",cscore,imscore,SLE);
        printf("Diagnostic result:\nBased on the 2019 EULAR/ACR classification criteria for SLE,\n");
        if(SLE>=10 && flag==1){
            printf("this patient is likely to be classified as SLE,the total weights add up to %d pts.\n",SLE);
            if(domainflag==0){
                printf("Main cause: Clinical:%s-%s\n",cdomain[bigdomain],cillness[bigillness]);
            }
            else{
                printf("Main cause:\nImmunology:%s-%s\n",imdomain[bigdomain],imillness[bigillness]);
            }
            printf("It gets %d pts of total %d pts and accounts for %.2f %% of total weights.\n",bigpoint,SLE,percent);
        }
        else if(flag==0){
            printf("because SLE classification requires at least one clinical criterion, so we may not classified as SLE.\n");
        }
        else{
            printf("this patient may not be classified as SLE\nThe total weights add up to only %d pts, which doesn't reach the standard 10 pts for SLE diagnosis.\n",SLE);
        }   
    }
    else{
        printf("Because the entry criterion isn't fulfilled, this patient may not be classified as SLE.\n");
    }
        return 0;
}