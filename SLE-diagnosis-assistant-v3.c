#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <limits.h>
int main(){
    int ANA=INT_MAX,b=0,c=0,ans=0,flag=0,SLE=0,point=0,t=0,q=0,cscore,imscore,gg=0,niflag=0,sledainum=0;
    char cdomain[50][50] = { {"Constitutional"}, {"Hematologic"},{"Neuropsychiatric"},{"Mucocutaneous"},{"Serosal"},{"Musculoskeletal"},{"Renal"} };
    char imdomain[50][50] = { {"Antiphospholipid antibodies"},{"Complement proteins"},{"SLE-specific antibodies"} };
    char cillness[50][50] = { {"Fever"},{"x"},{"Leukopenia"},{"Thrombocytopenia"},{"Autoimmune hemolysis"},{"x"},{"Delirium"},{"Psychosis"},{"Siezure"},{"x"},{"Non-scarring alopecia"},{"Oral ulcers"},{"Subacute cutaneous OR discoid lupus"},{"Acute cutaneous lupus"},{"x"},{"Pleural or pericardial effusion"},{"Acute pericarditis"},{"x"},{"Joint involvment"},{"x"},{"Proteinuria > 0.5g/24h"},{"Renal biopsy Class II or V lupus nephritis"},{"Renal biopsy Class III or IV lupus nephritis"},{"x"},{"c"} };
    char imillness[50][100] = { {"Anti-cardiolipin antibodies OR Anti-B2GP1 antibodes OR Lupus anticoagulant"},{"x"},{"Low C3 OR low C4"},{"Low C3 AND low C4"},{"x"},{"Anti-dsDNA antibody OR Anti-Smith antibody"},{"x"},{"c"} };
    char sledainame[50][500] = {{"Recent onset seizure"},{"Psychosis"},{"Organic brain syndrome"},{"Visual disturbance"},{"New onset sensory or motor neuropathy involving cranial nerves"},{"Lupus headache"},{"New onset stroke"},{"Vasculitis"},{"Arthritis"},{"Myositis"},{"Heme-granular or RBC urinary casts"},{"Hematuria"},{"Proteinuria"},{"Pyuria"},{"Inflammatory-type rash"},{"Alopecia"},{"Oral or nasal mucosal ulcers"},{"Pleuritic chest pain with pleural rub/effusion or pleural thickening"},{"Pericarditis"},{"Low complement"},{"High DNA binding"},{"Temp >100.4 degrees Fahrenheit (38 degrees Celsius)"},{"Platelets <100 x 10^9/L"},{"WBC <3 x 10^9/L"}};
    char sledaicontent[50][1000] = {{"Exclude metabolic, infectious, or drug causes"},{"Altered ability to function in normal activity due to severe disturbance in the perception of reality (include hallucinations, incoherence, marked loose associations, impoverished thought content, marked illogical thinking, and bizarre, disorganized, or catatonic behavior); exclude uremia and drug causes"},{"Altered mental function with impaired orientation, memory, or other intellectual function (with rapid onset and fluctuating clinical features), inability to sustain attention to environment, and >=2 of the following: perceptual disturbance, incoherent speech, insomnia or daytime drowsiness, and increased or decreased psychomotor activity; exclude metabolic, infectious, or drug causes"},{"Retinal changes of SLE (include cytoid bodies, retinal hemorrhages, serous exudates or hemorrhages in choroid, and optic neuritis); exclude hypertensive, infectious, or drug causes"},{"none"},{"Severe, persistent headache (may be migrainous but must be nonresponsive to narcotic analgesia)"},{"Exclude arteriosclerosis"},{"Ulceration, gangrene, tender finger nodules, periungual infarction, splinter hemorrhages or biopsy, and angiogram proof of vasculitis"},{">=2 joints with pain and signs of inflammation (i.e., tenderness, swelling, or effusion)"},{"Proximal muscle aching/weakness associated with elevated CPK/aldolase, EMG changes, or a biopsy showing myositis"},{"none"},{">5 RBC/high-power field; exclude stone, infection, or other cause"},{">0.5 g/24 hours"},{">5 WBC/high-power field; exclude infection"},{"none"},{"none"},{"none"},{"none"},{"Pericardial pain with >=1 of the following: rub, effusion, or EKG/echocardiogram confirmation"},{"CH50, C3, or C4 decreased below lower limit of normal for lab"},{"Increased above normal range for lab"},{"Exclude infectious causes"},{"Exclude drug causes"},{"Exclude drug causes"}};
    int sledaiweight[25] = {8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1};
    int sledaians[25] = {0};
    int cweight[50] = {2, 3, 4, 4, 2, 3, 5, 2, 2, 4, 6, 5, 6, 6, 4, 8, 10};
    int imweight[50] = {2, 3, 4, 6};
    int answer[50]={0};
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
            ANA = INT_MAX;
        }
    } while ( !(ANA>0) || ANA==INT_MAX );
    if(ANA<80 && ANA>0){
        printf("Additive criteria are needed before final diagnosis.\nThe following are some important conditions in clinical or immunological domains.\nPlease input \"Y\" if a patient meets the condition while input \"N\" if one doesn't,input \"B\" can back to previous question, input \"F\" can skip to next question.\n");       
        //Clinical domains and criteria
        printf("First, we need to know the patient's clinical conditions through the following questionaire.\n");
        for (int a = 1; a <= 8;a++){
            if(a<8){printf("%d. Questions about %s domain:\n", a, cdomain[a - 1]);}
            for (; b <= 24;b++){
                fflush(stdin);
                if(cillness[b][0]=='c'){
                    gg=0;
                    printf("The following illnesses are missing data:\n");
                    for (int ii = 0; ii < 17;ii++){
                        if(cillness[ii+gg][0]=='x'){
                            gg++;
                        }
                        if(answer[ii]==0){
                            printf("\"%s\"\n", cillness[ii+gg]);
                            niflag = 1;
                        }
                    }
                    if(niflag==0){
                        printf("none");
                    }
                    printf("\nPlease confirm your answer, input \"B\" can back to previous question, input \"F\" can continue to next part.\n");
                    scanf(" %c", &x);
                    switch(toupper(x)){
                        case 'B':
                            b = b - 3;
                            a--;
                            ans--;
                            if(b<-1){
                                b++;
                            }
                            else if(cillness[b+1][0]=='x'){
                                b = b - 1;
                                a = a - 1;
                            }
                            break;
                        case 'F':
                            break;
                        default:
                            printf("input \"B\"  or \"F\" only,try again.\n");
                            b = b - 1;
                            break;
                    }
                    continue;
                }
                if(cillness[b][0]=='x'){
                    b++;
                    break;
                }
                printf("%s ?\n", cillness[b]);
                //printf("ans:%d\n",ans);
                scanf(" %c", &x);
                switch(toupper(x)){
                    case 'Y':
                        answer[ans] = 2, ans++;
                        flag = 1;
                        break;
                    case 'N':
                        answer[ans] = 1, ans++;
                        break;
                    case 'B':
                        b = b - 2;
                        if(ans>0){ans--;}
                        if(b<-1){
                            b++;
                        }
                        else if(cillness[b+1][0]=='x'){
                            b = b - 1;
                            a = a - 1;
                        }
                        break;
                    case 'F':
                        ans++;
                        break;
                    default:
                        printf("input \" Y \" , \" N \" ,\" F \" or \"B\" only,try again.\n");
                        b = b - 1;
                        break;
                }
            }
        }
        niflag = 0;
        // Immunology domains and criteria
        printf("Then, we would like to further understand the patient's immunological conditions through the following questionaire\n");
        for (int a = 1; a <= 4;a++){
            if(a<4){printf("%d. Questions about %s domain:\n", a, imdomain[a - 1]);}
            for ( ; c <= 7;c++){
                fflush(stdin);
                if(imillness[c][0]=='c'){
                    int kk = 0;
                    int t = 0;
                    printf("The following illnesses are missing data:\n");
                    for (int ii = 17; ii < 21;ii++){
                        if(imillness[t+kk][0]=='x'){
                            kk++;
                        }
                        if(answer[ii]==0){
                            printf("\"%s\"\n", imillness[t+kk]);
                            niflag = 1;
                        }
                        t++;
                    }
                    if(niflag==0){
                        printf("none");
                    }
                    printf("\nPlease confirm your answer, input \"B\" can back to previous question, input \"F\" can continue to next part.\n");
                    scanf(" %c", &x);
                    switch(toupper(x)){
                        case 'B':
                            c = c - 3;
                            a--;
                            ans--;
                            if(c<-1){
                                c++;
                            }
                            else if(imillness[c+1][0]=='x'){
                                c = c - 1;
                                a = a - 1;
                            }
                            //printf("\n\nAAAAA %d A\n\n",b);
                            break;
                        case 'F':
                            ans++;
                            break;
                        default:
                            printf("input \"B\"  or \"F\" only,try again.\n");
                            c = c - 1;
                            break;
                    }
                    continue;
                }
                if(imillness[c][0]=='x'){
                    c++;
                    break;
                }
                printf("%s ?\n", imillness[c]);
                //printf("ans:%d\n",ans);
                scanf(" %c", &x);
                switch(toupper(x)){
                    case 'Y':
                        answer[ans] = 2, ans++;
                        break;
                    case 'N':
                        answer[ans] = 1, ans++;
                        break;
                    case 'B':
                        c = c - 2;
                        if(ans>17){ans--;}
                        if(c<-1){
                            c++;
                        }
                        else if(imillness[c+1][0]=='x'){
                            c = c - 1;
                            a = a - 1;
                        }
                        break;
                    case 'F':
                        ans++;
                        break;
                    default:
                        printf("input \" Y \" , \" N \" ,\" F \" or \"B\" only,try again.\n");
                        c = c - 1;
                        break;
                }
            }
        }
        //data processing
        for ( int x=0; x < 24;x++){
            if(cillness[x][0]=='x'){
                SLE = SLE + point;
                //printf("cpoint:%d\n",point);
                point = 0;
                continue;
            }
            if(point<=cweight[t]*(answer[t]-1)){
                point = cweight[t]*(answer[t]-1);
            }
            t++;
        }
        point = 0,cscore=SLE;
        for ( int x=0; x < 7;x++){
            if(imillness[x][0]=='x'){
                SLE = SLE + point;
                //printf("impoint:%d\n",point);
                point = 0;
                continue;
            }
            if(point<imweight[q]*(answer[t]-1)){
                point = imweight[q]*(answer[t]-1);
            }
            t++,q++;
        }
        imscore = SLE - cscore;
        //data output
        printf("\nThe total point of clinical score: %d pts\nThe total point of immunological score: %d pts\nThe total score is %d pts.\n",cscore,imscore,SLE);
        printf("Diagnostic result:\nBased on the 2019 EULAR/ACR classification criteria for SLE,\n");
        if(SLE>=10 && flag==1){
            printf("this patient is likely to be classified as SLE,the total weights add up to %d pts.\n",SLE);
            printf("\nAdditive criteria are needed to stratifies severity of SLE,\nPlease input \"Y\" if a patient meets the condition while input \"N\" if one doesn't,input \"B\" can back to previous question, input \"F\" can skip to next question.\n");
            for (int i = 0; i < 24;i++){
                printf("\n%s:\n%s\n", sledainame[i], sledaicontent[i]);
                fflush(stdin);
                scanf(" %c", &x);
                switch(toupper(x)){
                    case 'Y':
                        sledaians[i] = 2;
                        break;
                    case 'N':
                        sledaians[i] = 1;
                        break;
                    case 'B':
                        i = i - 2;
                        if(b<-1){
                            b++;
                        }
                        break;
                    case 'F':
                        i++;
                        break;
                    default:
                        printf("input \" Y \" , \" N \" ,\" F \" or \"B\" only,try again.\n");
                        b = b - 1;
                        break;
                }
            }
            for ( int x=0; x < 24;x++){
                if(sledaiweight[x]*(sledaians[x]-1)>0){
                    sledainum = sledainum + sledaiweight[x] * (sledaians[x] - 1);
                }
            }
            printf("According to SLEDAI-2K,\nSLEDAI point:%d", sledainum);
            if(sledainum==0){
                printf("(no activity)\n");
            }
            else if(sledainum<=5){
                printf("(mild activity)\n");
            }
            else if(sledainum<=10){
                printf("(moderate activity)\n");
            }
            else if(sledainum<20){
                printf("(high activity)\n");
            }
            else{
                printf("(very high activity)\n");
            }
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