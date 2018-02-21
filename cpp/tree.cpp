#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
using namespace std;

typedef struct tnode
{
    int data;
    tnode *left;
    tnode *right;
}tnode;

tnode * create(){

    int temp;
    cin>>temp;
    if(-1 == temp)
        return NULL;
    tnode *root = new tnode();
    root->data = temp;
    root->left = create();
    root->right = create();
    return root;    
}

tnode * create(int * a,int index,int len){
    if(index >= len || a[index] == -1)
        return NULL;
    tnode *root = new tnode();
    root->data = a[index];
    //cout<<"cur node data is : "<<a[index]<<endl;
    //cout<<"cur node parent is : "<<index<<endl;
    root->left = create(a,2*index+1,len);
    root->right = create(a,2*index+2,len);
    return root;
}
 
void pre_order(tnode *root){
    if(NULL == root)
        return;
    cout<<root->data<<endl;
    pre_order(root->left);
    pre_order(root->right);
    return;
}

void mid_order(tnode *root){
    if(NULL == root)
        return;
    mid_order(root->left);
    cout<<root->data<<endl;
    mid_order(root->right);
    return;
}

void post_order(tnode *root){
    if(NULL == root)
        return;
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<endl;
    return;
}

void level_travese(tnode * root){
    if(NULL == root)
        return;
    queue<tnode *> q;  
    q.push(root);
    int cur_level_num = 1;
    int next_level_num = 0;
    while(!q.empty()){
        tnode *tmp = q.front();
        q.pop();
        cout<<tmp->data<<"   ";
        cur_level_num --;
        if(tmp->left != NULL){
            q.push(tmp->left);
            next_level_num++;
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
            next_level_num++;
        }
        if(0 == cur_level_num){
            cout<<endl;
            cur_level_num = next_level_num;
            next_level_num = 0;
            
        }
    }
    return;
}
int getnodenum(tnode *root){
    if(NULL == root)
        return 0;
    return (getnodenum(root->left) + getnodenum(root->right) + 1);
}

int getdepth(tnode * root){
    if(NULL == root)
        return 0;
    return ((getdepth(root->left) > getdepth(root->right))?(getdepth(root->left)+1):(getdepth(root->right)+1));
}

int getleafnum(tnode * root){
    if(NULL == root)
        return 0;
    if(NULL == root->left && NULL == root->right)
        return 1;
    return (getleafnum(root->left) + getleafnum(root->right));
    
} 

int get_k_levelnum(tnode *root,int k){
    if(NULL == root || k < 1)
        return 0;
    if(1 == k)
        return 1;
    return (get_k_levelnum(root->left,k-1)+get_k_levelnum(root->right,k-1));
}
bool structure_cmp(tnode * root1, tnode * root2){
    if((NULL == root1) && (NULL == root2))
        return true;
    else if((NULL == root1) || (NULL == root2))
        return false;
    return (structure_cmp(root1->left,root2->left))&&(structure_cmp(root1->right,root2->right));
}

bool isavl(tnode * root, int & height){
    if(NULL == root){
        height = 0;
        return true;
    }
    int heightleft;
    bool resultleft = isavl(root->left,heightleft);
    int heightright;
    bool resultright = isavl(root->right,heightright);
    if(resultleft && resultright && (abs(heightleft-heightright) <= 1)){
        height = max(heightleft,heightright) + 1;
        return true;
    }else{
        height = max(heightleft,heightright) + 1;
        return false;
    }
    
}
tnode * get_mirror(tnode * root){
    if(NULL == root){
        return NULL;
    }
    tnode * left = get_mirror(root->left);
    tnode * right = get_mirror(root->right);
    root->left = right;
    root->right = left;
    return root;
}
bool is_complete_bt(tnode * root) {
    if(NULL == root)
        return false;
    queue<tnode *> q;
    bool musthavenochild = false;
    bool result = true;
    q.push(root);
    while(!q.empty()){
        tnode * tmp = q.front();
        q.pop();
        if(true == musthavenochild ){
            if(tmp->left != NULL || tmp->right != NULL){
                result = false;
                break;
            }
        }else{
            if(tmp->left !=NULL && tmp->right != NULL){
                q.push(tmp->left);
                q.push(tmp->right);
            }else if(tmp->left != NULL && tmp->right == NULL){
                q.push(tmp->left);
                musthavenochild = true;
            }else if(tmp->left == NULL && tmp->right != NULL ){
                result = false;
                break;
            }else{
                musthavenochild = true;
            }
        }
    }
    return result;
}
void treeprint(tnode *root,int level){
    if (!root) return;            //如果指针为空，返回上一层  
    treeprint(root->right,level+1);    //打印右子树，并将层次加1  
    for (int i=0;i<level;i++)    printf("   ");//按照递归的层次打印空格  
    printf("%d\n",root->data);  //输出根结点  
    treeprint(root->left,level+1);    //打印左子树，并将层次加1  
}  
int get_max_distance(tnode * root, int & maxleft, int & maxright){//maxleft,maxright,为左右叶子节点到根的最大距离
    if(NULL == root){
        maxleft = 0;
        maxright = 0;
        return 0;
    }
    int maxll,maxlr,maxrl,maxrr;
    int maxdistleft,maxdistright;
    if(root->left != NULL){
        maxdistleft = get_max_distance(root->left,maxll,maxlr);
        maxleft = max(maxll,maxlr) + 1;
    }else{
        maxdistleft = 0;
        maxleft = 0;
    }
    if(root->right != NULL){
        maxdistright = get_max_distance(root->right,maxrl,maxrr);
        maxright = max(maxrl,maxrr) + 1;
    }else{
        maxdistright = 0;
        maxright = 0;
    }
    return max(max(maxdistleft,maxdistright),maxleft + maxright);
}
bool  findnode(tnode *root,tnode *node){
    if(NULL == root || NULL == node)
        return false;
    if(root == node)
        return true;
    bool found = findnode(root->left,node);
    if(!found)
        found = findnode(root->right,node);
    return found;
}
tnode*  findnodebydata(tnode *root,int d){
    if(NULL == root || -1 == d)
        return NULL;
    if(d == root->data)
        return root;
    tnode *found = findnodebydata(root->left,d);
    if(NULL == found)
        found = findnodebydata(root->right,d);
    return found;
}
bool getnodepath(tnode *root, tnode * node,list<tnode *> & path){
    if(root == node){     
        path.push_back(root);  
        return true;  
    }  
    if(root == NULL)    return false;
    path.push_back(root);  
    bool found = false;  
    found = getnodepath(root->left, node, path);  
    if(!found)  
        found = getnodepath(root->right, node, path);  
    if(!found)    path.pop_back();
    return found;  
}  
tnode * get_last_common_parent_re(tnode * root,tnode * node1,tnode * node2){
    if(findnode(root->left,node1)){
        if(findnode(root->right,node2))
            return root;
        else
            return get_last_common_parent_re(root->left,node1,node2);
    }else{
        if(findnode(root->left,node2))
            return root;
        else
            return get_last_common_parent_re(root->right,node1,node2);
    }
}
tnode * get_last_common_parent_list(tnode * root, tnode * node1, tnode * node2)  
{  
    if(root == NULL || node1 == NULL || node2 == NULL)  
        return NULL;  
    list<tnode*> path1;  
    bool bresult1 = getnodepath(root, node1, path1);  
    list<tnode*> path2;  
    bool bresult2 = getnodepath(root, node2, path2);  
    if(!bresult1 || !bresult2)   
        return NULL;  
    
    tnode * plast = NULL;  
    list<tnode*>::const_iterator iter1 = path1.begin();  
    list<tnode*>::const_iterator iter2 = path2.begin();  
    while(iter1 != path1.end() && iter2 != path2.end())  
    {  
        if(*iter1 == *iter2)  
            plast = *iter1;  
        else  
            break;  
        iter1++;  
        iter2++;  
    }  
    return plast;  
}  
void convert_to_d_linklist(tnode * root,tnode * & first, tnode * & last) {
    if(NULL == root) {
        first = NULL;
        last = NULL;
        return;
    }
    tnode * fisrtleft,*lastleft,*firstright,*lastright;
    if(NULL == root->left){
        first = root;
    }else{
        convert_to_d_linklist(root->left,fisrtleft,lastleft);
        first = fisrtleft;
        lastleft->right = root;
        root->left = lastleft;
    }
    if(NULL == root->right){
        last = root;
    }else{
        convert_to_d_linklist(root->right,firstright,lastright);
        last = lastright;
        firstright->left = root;
        root->right = firstright;
    }
    return;
}
tnode * rebuild_from_pre_in(int* pre, int* in, int nodenum){
    if(NULL == pre || NULL == in || nodenum <= -1) return NULL;
    tnode * root = new tnode();
    root->data = pre[0];
    root->left = root->right = NULL;
    int rootposition = -1;
    for(int i = 0;i<nodenum;i++){
        if(root->data = in[i]){
            rootposition = i;
            break;
        }
    }
    if(-1 != rootposition){
        root->left = rebuild_from_pre_in(pre+1,in,rootposition);
        root->right = rebuild_from_pre_in(pre+rootposition+1,in+rootposition+1,nodenum - rootposition -1);
    }
}
void preOrder2_non_re(tnode *root)     //非递归前序遍历 
{
    stack<tnode*> s;
    tnode *p=root;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){
            cout<<p->data<<"  ";
            s.push(p);
            p=p->left;
        }
        if(!s.empty()){
            p=s.top();
            s.pop();
            p=p->right;
        }
    }
}
void inOrder2_non_re(tnode *root)     //非递归中序遍历 
{
    stack<tnode*> s;
    tnode *p=root;
    while(p!=NULL||!s.empty()){
        while(p!=NULL){

            s.push(p);
            p=p->left;
        }
        if(!s.empty()){
            p=s.top();
            cout<<p->data<<"  ";
            s.pop();
            p=p->right;
        }
    }
}
void postOrder3_non_re(tnode *root){//非递归后序遍历
    stack<tnode*> s;
    tnode *cur;                      //当前结点 
    tnode *pre = NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty()){
        cur = s.top();
        if((cur->left==NULL&&cur->right==NULL)||(pre!=NULL&&(pre==cur->left||pre==cur->right))){
            cout<<cur->data<<"  ";  //如果当前结点没有孩子结点,或者孩子节点都已被访问过 
            s.pop();
            pre = cur; 
        }else{
            if(cur->right!=NULL)    s.push(cur->right);
            if(cur->left!=NULL)    s.push(cur->left);
        }
    }    
}
int main(){
    int a[] = {1,2,3,-1,-1,-1,-1};
    int b[] = {11,22,33,-1,-1,-1,-1};
    int c1[] = { 1, 2, 3, -1, -1, 4, -1,-1,5,6,-1,-1,7,-1,8 };//15,无左孩子，有右孩子
    int c2[] = { 1, 2, 3, 8, -1, -1, -1, 4, -1, -1, 5, 6, -1, -1, 7 };//15 最下面一层有一个孩子，且是左孩子
    int c3[] = { 1, 2, 3, -1, 9, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1 };//15 最下面一层有一个孩子，且是右孩子
    int c4[] = { 1, 2, 3, -1, -1, 4, -1, -1, 5, 6, -1, -1, 7, -1, -1 };//15最下面一层全部是叶子节点
    int c5[] = { 1, 2, 3, 8, -1, -1,-1, 4,9, -1, -1,-1, 5, 6, -1, -1, 7 };//17 上迎面解释的这种情况
    int c6[] = { 1 };//只有一个根节点
    int c7[] = { -1};//空树
    tnode *root1 = create(a,0,7);
    tnode *root2 = create(b,0,7);
    tnode *root3 = create(c5,0,17);
    int height, maxleft,maxright;
    cout<<"mid order :"<<endl;
    mid_order(root3);
    cout<<"post order :"<<endl;
    post_order(root3);
    cout<<"pre order :"<<endl;
    pre_order(root3);
    cout<<"level_travese:"<<endl;
    level_travese(root3);
    cout<<"tree node num is :"<<getnodenum(root1)<<endl;
    cout<<"tree depth is :"<<getdepth(root1)<<endl;
    cout<<"tree leaf num is :"<<getleafnum(root1)<<endl;
    cout<<"tree level 2 ,node num is:"<<get_k_levelnum(root1,2)<<endl;
    cout<<"tree 1 and tree 2 ,structure compare result:"<<structure_cmp(root1,root2)<<endl;
    cout<<"tree is avl or not?"<<isavl(root1,height)<<endl;
    cout<<"after get mirror  pre_order again:"<<endl;
    pre_order(get_mirror(root1));
    cout<<"tree print root1"<<endl;
    treeprint(root1,0);
    cout<<"tree print root2"<<endl;
    treeprint(root2,0);
    cout<<"tree print root3"<<endl;
    treeprint(root3,0);
    cout<<"is the tree c  a complete binary tree : "<<is_complete_bt(root3)<<endl;
    cout<<"get max distence in tree:"<<get_max_distance(root3,maxleft,maxright)<<endl;
    tnode *node1 = findnodebydata(root3,8);
    cout<<"node1->data is : "<<node1->data<<endl;
    cout<<"non recursive preOrder travese root3 :"<<endl;
    preOrder2_non_re(root3);
    cout<<endl;
    cout<<"non recursive inOrder travese root3 :"<<endl;
    inOrder2_non_re(root3);
    cout<<endl;
    cout<<"non recursive post Order travese root3 :"<<endl;
    postOrder3_non_re(root3);
    cout<<endl;
    return 0;
}
/*
       1
      /\
     2  3
    /
   8
  /\
 4  9
 \
  7
  */