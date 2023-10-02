 #include <stdio.h>

int main()
{
    FILE*  fp1;
    FILE*  fp2;
    int n,i;
    int ssn;
    float wages, wagestotal=0;
    //char word[30],word2[30];

    //printf("type input fname:");
    //scanf("%s",word);
    //printf("type output fname:");
    //scanf("%s",word2);

     fp1 = fopen("inputfile1.txt", "r");
     //fp2 = fopen(word2,"w");

     fscanf(fp1,"%d", &n);

     for(i=0;i<n;i++)
      {
          fscanf(fp1,"%d%f", &ssn, &wages);
          printf("%d\n", ssn);
          printf("%.2f\n", wages);
          wagestotal += wages;
      }

    printf("Ave of the wages: $%.2f\n", (wagestotal/n));

    //fprintf(fp2,"%f", wagestotal/n);

    fclose(fp1);
    //fclose(fp2);
   return 0;
}
