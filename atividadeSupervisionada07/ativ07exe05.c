int main()
{
    int fios;
    //coloquei como int porque estava dando erro dizendo que não dá pra usar float no %.
    
    printf("Qual quantidade total de fios em metros que serão utilizados na obra? ");
    scanf("%i", &fios);
    
    printf("\n");
    printf("Serão necessários %i rolos de fio.\n", (fios / 50));
    printf("E será preciso %im de fios avulsos.\n", (fios % 50));
    return 0;
}