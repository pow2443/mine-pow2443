#include<stdio.h>
#include<stdlib.h>

char *map=NULL;
char *mist=NULL;

void setMap(int x, int y)
{
    
    int i=0,j=0;
    
    map = malloc(y*x*sizeof(char));
    if(map==NULL)
    {
        printf("Fail getting memory size");
    }
    else
    {
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                *(map+(i*x)+j)=0;
            }
        }
    }
    
}

void setMine(int x,int y,int mine)
{
    
    int i=0,j=0,tmp=0;
    
    srand(time(NULL));
    
    for(i=0;i<mine;i++)
    {        
        tmp = rand()%(x*y);
        if(*(map+tmp)=='*')
        {
            for(;*(map+tmp)!='*';)
            {
            tmp = rand()%(x*y);
            }
        }
        
        *(map+tmp)='*';
        
    }
      
}

void setHint(int x, int y)
{
    int i=0,j=0,tmp=0;
    
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(*(map+(x*i)+j)!='*')
            {   
                if((i==0)&&(j==0))
                {
                    if(*(map+(x*i)+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if((i==0)&&(j!=0))
                {
                    if(*(map+(x*i)+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*i)+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if((i==0)&&((j+1)==y))
                {
                    if(*(map+(x*i)+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if((i!=0)&&(j==0))
                {
                    if(*(map+(x*(i-1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i-1))+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*i)+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if((i!=0)&&(j==(y-1)))
                {
                    if(*(map+(x*(i-1))+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i-1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;                   
                    if(*(map+(x*i)+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i+1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if(((i+1)==x)&&(j==0))
                {
                    if(*(map+(x*(i-1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i-1))+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*i)+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if(((i+1)==x)&&(j!=0))
                {
                    if(*(map+(x*(i-1))+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i-1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i-1))+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*i)+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*i)+(j+1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else if(((i+1)==x)&&(j==(y-1)))
                {
                    if(*(map+(x*(i-1))+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*(i-1))+j)=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                    if(*(map+(x*i)+(j-1))=='*')
                    *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
                else
                {
                if(*(map+(x*(i-1))+(j-1))=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*(i-1))+j)=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*(i-1))+(j+1))=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*i)+(j-1))=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*i)+(j+1))=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*(i+1))+(j-1))=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*(i+1))+j)=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                if(*(map+(x*(i+1))+(j+1))=='*')
                *(map+(x*i)+j)=*(map+(x*i)+j)+1;
                }
            }
        }
    }
    
}

void mistMap(int x, int y)
{    
    int i=0,j=0; 
    
    mist=malloc(x*y*sizeof(char));
   
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            *(mist+(x*i)+j)='B';
        }
    }
    
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%2c", *(mist+(x*i)+j));
        }
        printf("\n");
    }
    
}

int displayMap(int x, int y, int xLoc, int yLoc, int mine)
{
    int i=0, j=0, key=0; 
    
    *(mist+(x*(xLoc-1))+(yLoc-1)) = *(map+(x*(xLoc-1))+(yLoc-1));
    
    if(*(mist+(x*(xLoc-1))+(yLoc-1))=='*')
    {
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if((*(mist+(i*x)+j)=='*')||(*(mist+(i*x)+j)=='B'))
                { 
                printf("%2c ",*(mist+(i*x)+j));
                }
                else{
                printf("%2d ",*(mist+(i*x)+j));
                }
            }
            printf("\n");
        }
        printf("\n");
        printf("There is a mine in your input location\n");
        printf("Game Over!");
        return -1;
    }
    else
    {   
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(*(mist+(i*x)+j)=='B')
                { 
                printf("%2c ",*(mist+(i*x)+j));
                key = key+1;
                }
                else{
                printf("%2d ",*(mist+(i*x)+j));
                }
            }
            printf("\n");
        }
        if(key==mine)
        printf("Congratulation! You won in the game"); 
        return key;
    }
    
}

int main (void)
{
    
    int x=0,y=0,mine=0;
    int i=0,j=0,key=0;
    int xLoc=0,yLoc=0;
    
    printf("Enter the size of map(ex: ?*?) in 20*20 : ");
    scanf("%d*%d",&x,&y);
    
    printf("Enter number of mines: ");
    scanf("%d", &mine);
    
    if((mine>=(x*y))||(mine<=0))
    {
        do{
        printf("Sorry, You entered many or less mines than the map size\n");
        printf("Try to input the number of mines again!\n");
        printf("Enter number of mines: ");
        scanf("%d", &mine);
        }while((mine<(x*y))&&(mine>=0));
    }
    
    setMap(x,y);
    setMine(x,y,mine);
    setHint(x,y);
    mistMap(x,y);
   
    for(;(key!=-1)&&(key!=mine);)
    {
        
        printf("Enter what you want to open a location(ex:?*?) : ");
        scanf("%d*%d", &xLoc, &yLoc);
        key=displayMap(x,y,xLoc,yLoc,mine);
        
    }
    
    
    free(map);
    free(mist);
    
    return 0;
    
}
