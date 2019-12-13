#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>


typedef struct node
{
   char* var;
   int value;

   struct node* next;

}node;


int find(char* r, node* h);
void flip(int b,char* v, node* h);
void plus(char* add, node* ptr);
void setArr(int** array, int numRows,int numColumns);
void printArr(int** array, int numRows,int numColumns);

int main(int argc, char* argv[])
{

  FILE* f = fopen(argv[1],"r");
  if(f == NULL) return 0;

  int iVars;
  int oVars;

  fscanf(f,"%*s %d", &iVars);

   node* iVar = NULL;
   node* oVar = NULL;

   int i;

   for(i=0 ; i < iVars; i++)
    {

	char* holder =(char*) malloc(20*sizeof(char));
         fscanf(f,"%s", holder);

         if(iVar == NULL)
	   {
	     node* make = (node*)malloc(sizeof(node));
             make->next = NULL;
             make->var = holder;
             iVar = make;

	   }
	 else
	   {
             plus(holder,iVar);
           }


      }

    fscanf(f,"%*s %d\n",&oVars);
    int k;
    for(k=0 ; k < oVars; k++)
    {

	char* holder =(char*) malloc(20*sizeof(char));
         fscanf(f,"%s", holder);
         if(oVar == NULL)
	   {
	     node* make = (node*)malloc(sizeof(node));
             make->next = NULL;
             make->var = holder;
             oVar = make;

	   }
	 else
	   {
             plus(holder,oVar);
           }


      }




int c;
    int** gird = (int**)malloc((int)pow(2,iVars)*sizeof(int*));
  
    for(c = 0; c <(int) pow(2,iVars);c++)
      {
	gird[c]= (int*)malloc((iVars + oVars)*sizeof(int));


      }
    setArr(gird,(int)pow(2,iVars),iVars +oVars);


    int freq=1;
    int swVar= 0;
    
    int ctr = 0;
    int r,  col;
    
    int gridRow = (int)pow(2,iVars);
    int gridCol = iVars + oVars;


    for( col = iVars -1; col >= 0; col--)
      {
	swVar = 0;
	ctr = 0;
  
	for(r = 0; r < (int)pow(2,iVars); r++)
	  {
	    if(ctr == freq)
	      {
		if(swVar ==0){ swVar =1;}
                else { swVar = 0; }
                ctr = 0;

	      }
	    gird[r][col]= swVar;
	      ctr++;

	  }
	freq = freq *2;


      }


    int r1,c1;

    for(r1 = 0; r1 < gridRow  ;r1++)
      {

        node* add = iVar;
	for(c1 = 0; c1 < gridCol -oVars; c1++)
	  {

	    int adding = gird[r1][c1];

            add->value = adding;

            add = add->next;

          }


         char* oper = malloc(5*sizeof(char));
          
          fclose(f);
          f= fopen(argv[1],"r");
          
          fscanf(f,"%*[^\n]");
          fscanf(f,"\n");
          fscanf(f,"%*[^\n]");
          fscanf(f,"\n");
          
	 while(fscanf(f,"%s",oper)!= EOF) {

	    char* fVar = malloc(20*sizeof(char));

            fscanf(f,"%s",fVar);

            char* secVar = malloc(20*sizeof(char));
             fscanf(f,"%s",secVar);

            if(strcmp("NOT",oper)==0 )
	     {

               if(secVar[0] >= 'a' && secVar[0] <= 'z')
		 {
		   if(find(secVar,iVar) == -1)
		     {
		       plus(secVar,iVar);

                     }

                 }
	       if(find(fVar,iVar)!= -1)
		 {

		   int negate = !find(fVar,iVar);

		   if(find(secVar,iVar) != -1)
                     {

                       flip(negate,secVar,iVar);
                     }
                   else if(find(secVar,oVar) != -1)
                     {
                       flip(negate,secVar,oVar);

                     }

                 }
	       else
		 {
		   int negate = !find(fVar,oVar);
                     if(find(secVar,iVar) != -1)
                     {

                       flip(negate,secVar,iVar);

                     }
                   else if(find(secVar,oVar) != -1)
                     {
                       flip(negate,secVar,oVar);
                     }

                 }

             }

                 if(strcmp("OR",oper)==0 )
	       {
		 int temp1;
                 int temp2;
                 int fy;
                 if(find(fVar,iVar)!= -1){ 

		temp1 = find(fVar,iVar);

		}
                 else 
		{
		temp1 = find(fVar,oVar);
		}                

		 if(find(secVar,iVar)!= -1){
		
		 temp2 = find(secVar,iVar);
		} else
		{
		 temp2 = find(secVar,oVar);
		}

		 fy = temp1 || temp2;

                 char* thirdV = malloc(20*sizeof(char));
                 fscanf(f,"%s",thirdV);
                 if(thirdV[0] >= 'a' && thirdV[0] <= 'z')
		   {
		     if(find(thirdV,iVar) == -1) plus(thirdV,iVar);
                   }

                 if(find(thirdV,iVar) != -1) 
		{
            flip(fy,thirdV,iVar);
        }
        else{
            flip(fy,thirdV,oVar);
               }
		}


                if(strcmp("XOR",oper)==0 )
	       {
		 int temp1;
                 int temp2;
                 int fy;
                 if(find(fVar,iVar)!= -1)
		   { temp1 = find(fVar,iVar);
		   }else
			{
 		    temp1 = find(fVar,oVar);
			}
                 
		if(find(secVar,iVar)!= -1)
		  { temp2 = find(secVar,iVar);
		  }
                 else 
			{temp2 = find(secVar,oVar);
		}

		 fy = temp1 ^ temp2;

                 char* thirdV = malloc(20*sizeof(char));
                 fscanf(f,"%s",thirdV);
                 if(thirdV[0] >= 'a' && thirdV[0] <= 'z')
		   {
		     if(find(thirdV,iVar) == -1) plus(thirdV,iVar);
                   }

                 if(find(thirdV,iVar) != -1) flip(fy,thirdV,iVar);

                 else flip(fy,thirdV,oVar);
               }

	 if(strcmp("AND",oper)==0 )
               {
                 int temp1;
                 int temp2;
                 int fy;
                 if(find(fVar,iVar)!= -1)
                 {
		    temp1 = find(fVar,iVar);
                  
                }
                 else{
			temp1 = find(fVar,oVar);
		  }
                 if(find(secVar,iVar)!= -1)
		{
            temp2 = find(secVar,iVar);
			}
                 else {
			temp2 = find(secVar,oVar);
			}
                 fy = temp1 && temp2;

                 char* thirdV = malloc(20*sizeof(char));
                 fscanf(f,"%s",thirdV);
                 if(thirdV[0] >= 'a' && thirdV[0] <= 'z')
                   {
                     if(find(thirdV,iVar) == -1) plus(thirdV,iVar);


                   }

                 if(find(thirdV,iVar) != -1) flip(fy,thirdV,iVar);

                 else flip(fy,thirdV,oVar);


               }





 if(strcmp("NAND",oper)==0 )
               {
                 int temp1;
                 int temp2;
                 int fy;
                 if(find(fVar,iVar)!= -1){ 
			temp1 = find(fVar,iVar);
                   }
                 else {
			temp1 = find(fVar,oVar);
                  }
                 if(find(secVar,iVar)!= -1)
		{ 
			temp2 = find(secVar,iVar);
                 }
                 else {
			temp2 = find(secVar,oVar);
		}
                 fy = !(temp1 && temp2);

                 char* thirdV = malloc(20*sizeof(char));
                 fscanf(f,"%s",thirdV);
                 if(thirdV[0] >= 'a' && thirdV[0] <= 'z')
                   {
                     if(find(thirdV,iVar) == -1) plus(thirdV,iVar);

                   }

                 if(find(thirdV,iVar) != -1) flip(fy,thirdV,iVar);

                 else flip(fy,thirdV,oVar);

               }

 if(strcmp("NOR",oper)==0 )
               {
                 int temp1;
                 int temp2;
                 int fy;
                 if(find(fVar,iVar)!= -1){ 
			temp1 = find(fVar,iVar);
                     }
                 else {
			temp1 = find(fVar,oVar);
		}
                 if(find(secVar,iVar)!= -1)
		{ 
			temp2 = find(secVar,iVar);
		}
                 else {
			temp2 = find(secVar,oVar);
			}
                 fy = !(temp1 || temp2);

                 char* thirdV = malloc(20*sizeof(char));
                 fscanf(f,"%s",thirdV);
                 if(thirdV[0] >= 'a' && thirdV[0] <= 'z')
                   {
                     if(find(thirdV,iVar) == -1) plus(thirdV,iVar);

                   }

                 if(find(thirdV,iVar) != -1) flip(fy,thirdV,iVar);

                 else flip(fy,thirdV,oVar);


               }


	 }
        node* temp = oVar;
        for(c1 = gridCol - oVars; c1 < gridCol ; c1++)
	  {

	    gird[r1][c1] = temp->value;
            temp = temp->next;
          }

      }
    printArr(gird,gridRow,gridCol);

  return 0;
}


int find(char* r, node* h)
{
  node* current;
  for(current = h; current!= NULL; current= current->next)
    {
      if(strcmp(current->var,r) == 0)

	{
	  return current->value;

        }

    }

  return -1;

}

void plus(char* add, node* ptr)
{
  node* holder;
  node* plus = (node*)malloc(sizeof(node));


  plus->var = malloc(20*sizeof(char));
  strcpy(plus->var,add);
  plus->next = NULL;

  for(holder = ptr; holder != NULL; holder = holder->next)
    {

      if(holder->next == NULL)
	{

	  holder->next = plus;
          break;

        }

    }

}

void setArr(int** array, int numRows,int numColumns)
{
  int r,  c;
   for(r = 0; r < numRows; r++)
      {

	for(c = 0; c < numColumns; c++)
	  {
	    array[r][c]=0;

	  }

      }

}

void printArr(int** array, int numRows,int numColumns)
{
  int r,c;
   for(r = 0; r < numRows; r++)
      {

	for(c = 0; c < numColumns; c++)
	  {
	    printf("%d ",array[r][c]);

	  }
	printf("\n");
      }

}

void flip(int b,char* v, node* h)
{
    node* holder;
   for(holder = h; holder != NULL; holder = holder->next)
    {
      if(strcmp(holder->var,v) == 0)
	{
	  holder->value = b;
          break;


        }

    }
}



