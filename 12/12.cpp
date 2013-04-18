// 12.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
using namespace std;

struct TREE {
int info, count; 
TREE *left, *right;
};

TREE *root=NULL;
int flag=0;
int count=0;

TREE *Search(int info)
{
TREE *current=root; 
flag=0; 
while(current!=NULL && flag==0) 
{ 
if(info<current->info) 
current=current->left; 
else if(info>current->info) 
current=current->right; 
else 
flag=1; 
} 
return current;
}

void Add(TREE **current, int info)
{
if(*current!=NULL) 
{ 
if(info<(*current)->info) 
Add(&(*current)->left, info); 
else if(info>(*current)->info) 
Add(&(*current)->right, info); 
else 
(*current)->count++; 
} 
else 
{ 
*current= new TREE; 
(*current)->info=info; 
(*current)->left=NULL; 
(*current)->right=NULL; 
(*current)->count=1; 
count++; 
}
}

void AddLoop(int info)
{
if(root==NULL) 
{ 
root= new TREE; 
root->info=info; 
root->right=NULL; 
root->left=NULL; 
root->count=1; 
count++; 
} 
else 
{ 
TREE *current=root; 
TREE *parent; 
while(current!=NULL) 
{ 
parent=current; 
if(info<current->info) 
current=current->left; 
else if(info>current->info) 
current=current->right; 
else 
{ 
current->count++; 
current=NULL; 
} 
} 
if(info<parent->info) 
{ 
current= new TREE; 
current->left=NULL; 
current->right=NULL; 
current->info=info; 
current->count=1; 
parent->left=current; 
count++; 
} 
else if(info>parent->info) 
{ 
current= new TREE; 
current->left=NULL; 
current->right=NULL; 
current->info=info; 
current->count=1; 
parent->right=current; 
count++; 
} 
}
}

void Changer(TREE **current, TREE **tmp)
{
if((*current)->right!=NULL) 
Changer(&(*current)->right, &(*tmp)); 
else 
{ 
(*tmp)->info=(*current)->info; 
*tmp=*current; 
*current=(*current)->left; 
}
}

int Delete (TREE **current, int info)
{
int r=0; 
if(*current!=NULL) 
{ 
if(info<(*current)->info) 
r=Delete(&(*current)->left, info); 
else if(info>(*current)->info) 
r=Delete(&(*current)->right, info); 
else 
{ 
TREE *tmp=*current; 
if(tmp->right==NULL) 
*current=tmp->left; 
else if(tmp->left==NULL) 
*current=tmp->right; 
else 
Changer(&(*current)->left, &tmp); 
delete tmp; 
count; 
r=1; 
} 
} 
return r;
}

void ShowBackSymmetric(TREE *current, int l)
{
if(current!=NULL) 
{ 
ShowBackSymmetric(current->right, l+1); 
for( int i=0; i<l; i++) 
cout « "\t"; 
cout « current->info « endl; 
ShowBackSymmetric(current->left, l+1); 
}
}

void Show(TREE *current)
{
if(current!=NULL) 
{ 
Show(current->left); 
cout « current->info « '(' « current->count « ')' « ' '
; 
Show(current->right); 
}
}

void Clear(TREE **current)
{
if(*current!=NULL) 
{ 
Clear(&(*current)->left); 
Clear(&(*current)->right); 
delete *current; 
count; 
if(count==0) 
*current=NULL; 
}
}

int main()
{
setlocale(LC_ALL,"Russian"); 
int n,num; 
char otv; 
do 
{ 
cout « endl « "1. Создать" 
« endl « "2. Добавить" 
« endl « "3. Добавить (цикл)" 
« endl « "4. Удалить" 
« endl « "5. Обратно-симметричный обход" 
« endl « "6. Вывод со счетчиком" 
« endl « "7. Очистить" 
« endl « "0. Выход" 
« endl « " = "; 
cin » otv; 
switch(otv) 
{ 
case '1': 
cout « endl « "Кол-во элементов = "; 
cin » n; 
for ( int i=0; i<n; i++) 
{ 
num=rand()%100; 
Add(&root, num); 
} 
cout « endl « "Элементы добавлены" « endl; 
break;
case '2':
cout « endl « "Введите элемент = "; 
cin » num; 
Add(&root, num); 
cout « endl « "Элемент добавлен" « endl; 
break;
case '3':
cout « endl « "Введите элемент = "; 
cin » num; 
AddLoop(num); 
cout « endl « "Элемент добавлен" « endl; 
break;
case '4':
if(root!=NULL) 
{ 
cout « endl « "Удаляемый элемент = "; 
cin » num; 
if(Delete(&root, num)==1) 
cout « endl « "Элемент удален" « endl; 
else 
cout « endl « "Элемент не найден" « endl; 
} 
else 
cout « endl « "Дерево пустое" « endl; 
break;
case '5':
if(root!=NULL) 
{ 
ShowBackSymmetric(root,0); 
} 
else 
cout « endl « "Дерево пустое" « endl; 
break;
case '6':
if(root!=NULL) 
{ 
Show(root); 
} 
else 
cout « endl « "Дерево пустое" « endl; 
break;
case '7':
Clear(&root); 
cout « endl « "Дерево очищено" « endl; 
break;
case '0':
break;
default:
cout « endl « "Ошибка" « endl; 
break;
}

}while(otv!='0');
cin.ge
}
 
