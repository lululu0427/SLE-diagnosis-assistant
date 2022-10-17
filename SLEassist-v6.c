#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <limits.h>
#include <time.h>
#include "function.h"
int main(){
    int ANA = INT_MAX,flag = 0, SLE = 0,cscore,sledainum = 0;
    char activity[6][50] = {{"no activity"}, {"mild activity"}, {"moderate activity"}, {"high activity"}, {"very high activity"}};
    int sledaians[25] = {0};
    int answer[50]={0};
    char  issle; 
    //excel define
    int ID = 0, aty=0;
    char name[50],isSLE='Y';
    printf("----Welcome to SLE diagnosis assistant!----\n");
    FILE *fp;
	fp = fopen("C:\\Users\\user\\Desktop\\tmp\\SLE.csv", "a");
	if(fp==NULL){
		printf("Error openning the file\n");
		return 1;
	}
    id(&ID);
    scanf("%[^\n]",name);
    fflush(stdin);
    beenSLE(&issle);
    if(issle=='N'){
        ananum(&ANA);
        if(ANA<80 && ANA>0){
            flag=answerinput(answer, 0);
            flag=answerinput(answer, 1);
            //data processing
            datamake(&SLE, &cscore, answer);
            //data output
            printf("\nThe total point of clinical score: %d pts\nThe total point of immunological score: %d pts\nThe total score is %d pts.\n",cscore,SLE - cscore,SLE);
            printf("\n\nDiagnostic result:\nBased on the 2019 EULAR/ACR classification criteria for SLE,\n");
            if(SLE>=10 && flag==1){
                isSLE = 'Y';
                printf("this patient is likely to be classified as SLE,the total weights add up to %d pts.\n\nAdditive criteria are needed to stratifies severity of SLE,\nPlease input \"Y\" if a patient meets the condition while input \"N\" if one doesn't,input \"B\" can back to previous question, input \"F\" can skip to next question.\n",SLE);
                sledaifunc(sledaians,&sledainum, &aty);
            }
            else if(flag==0){
                isSLE = 'N';
                printf("because SLE classification requires at least one clinical criterion, so we may not classified as SLE.\n");
            }
            else{
                isSLE = 'N';
                printf("this patient may not be classified as SLE\nThe total weights add up to only %d pts, which doesn't reach the standard 10 pts for SLE diagnosis.\n",SLE);
            }   
        }
        else{
            printf("Because the entry criterion isn't fulfilled, this patient may not be classified as SLE.\n");
        }
    }
    else{
        printf("This patient is a SLE patient.\nHere are some criterias to stratifies severity of SLE,\nPlease input \"Y\" if a patient meets the condition while input \"N\" if one doesn't,input \"B\" can back to previous question, input \"F\" can skip to next question.\n");
        sledaifunc(sledaians,&sledainum, &aty);
    }
	time_t now;
    time(&now);
	//save
    fprintf(fp,"%d,%s,%d,%c,%d,%s", ID,name,SLE,isSLE,sledainum,activity[aty]);
    for (int i = 0; i < 21;i++){
        if(answer[i]==2){
            fprintf(fp,",Yes");
        }
        else if(answer[i]==1){
            fprintf(fp,",No");
        }
        else{
            fprintf(fp,",Missing Value");  
        }
    }
    fprintf(fp,",%s",ctime(&now));
    //fprintf(fp,"\n");
	if(ferror(fp)){
		printf("Error writing to file.\n");
		return 1;
	}
    exit(0);
	fclose(fp);
    return 0;
}