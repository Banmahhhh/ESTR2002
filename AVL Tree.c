#include <stdio.h>
#include <malloc.h>
struct AVLNode
{
    int val;
    struct AVLNode *left,*right;
    int height;//AVL树的高度
};
typedef struct AVLNode AVLNode;
int Max(int a,int b){
    return a>b?a:b;
}
int cptHeight(AVLNode *r){
    return r?r->height:-1;
}
AVLNode *lRotation(AVLNode *r)
{
    AVLNode *p=r->right;
    r->right=p->left;
    p->left=r;
    r->height=Max(cptHeight(r->left),cptHeight(r->right))+1;
    p->height=Max(cptHeight(p->left),cptHeight(p->right))+1;
    return p;
}
AVLNode *rRotation(AVLNode *r)
{
    AVLNode *p=r->left;
    r->left=p->right;
    p->right=r;
    r->height=Max(cptHeight(r->left),cptHeight(r->right))+1;
    p->height=Max(cptHeight(p->left),cptHeight(p->right))+1;
    return p;
}
AVLNode *lrRotation(AVLNode *r)
{
    r->left=lRotation(r->left);
    return rRotation(r);
}
AVLNode *rlRotation(AVLNode *r)
{
    r->right=rRotation(r->right);
    return lRotation(r);
}
AVLNode *AVLinsert(AVLNode *r,int e)
{
    if(r==NULL){
        r=(AVLNode*)malloc(sizeof(AVLNode));
        r->val=e;
        r->left=r->right=NULL;
        r->height=0;//叶节点高度定义为0;
        return r;
    }
    if(r->val<e){
        r->right=AVLinsert(r->right,e);//在r右子树中插入节点
        if(cptHeight(r->right)-cptHeight(r->left)>=2){//插入节点后可能引起失衡
            r=(cptHeight(r->right->left)>cptHeight(r->right->right))?rlRotation(r):lRotation(r);
            //失衡节点r右子树的左右高度不可能相同
            //r右子树左边高度大于右边，新插入节点在左边，应进行rl旋转，否则进行l旋转
        }
    }
    else if(r->val>e){
        r->left=AVLinsert(r->left,e);//在r左子树中插入节点
        if(cptHeight(r->left)-cptHeight(r->right)>=2){//插入节点后可能引起失衡
            r=(cptHeight(r->left->left)>cptHeight(r->left->right))?rRotation(r):lrRotation(r);
            //失衡节点r左子树的左右高度不可能相同
            //左子树左边高度大于右边，新插入节点在左边，应进行r旋转，否则进行lr旋转
        }
    }
    else printf("insert the same node\n");
    r->height=Max(cptHeight(r->left),cptHeight(r->right))+1;
    return r;
}
AVLNode *AVLremove(AVLNode *r,int e)
{
    if(r==NULL) return r;
    if(r->val<e){
        r->right=AVLremove(r->right,e);
    }
    else if(r->val>e){
        r->left=AVLremove(r->left,e);
    }
    else{//找到当前需要删除的值
        if(r->left&&r->right){//左右儿子都不为空
            AVLNode *p=r->right;
            while(p->left) p=p->left;//右边子树最小的值
            r->val=p->val;
            r->right=AVLremove(r->right,p->val);
        }
        else{
            AVLNode *p=(r->left)?r->left:r->right;
            free(r);
            return p;
        }
    }
    if(cptHeight(r->left)-cptHeight(r->right)>=2){//对右边节点进行删除引起失衡
        r=(cptHeight(r->left->left)>cptHeight(r->left->right))?rRotation(r):lrRotation(r);
        //注意，此时失衡节点r左子树左右高度可能相等，相等时，采取不同的旋转策略将得到不同的AVL树
    }else if(cptHeight(r->right)-cptHeight(r->left)>=2){//对左边节点进行删除引起失衡
        r=(cptHeight(r->right->left)>cptHeight(r->right->right))?rlRotation(r):lRotation(r);
        //同上
    }
    r->height=Max(cptHeight(r->left),cptHeight(r->right))+1;
    //更新相应的节点高度值
    return r;
}
void pretra(AVLNode *r)//前序
{
    if(r){
        printf("<%d, %d> ",r->val,r->height);
        pretra(r->left);
        pretra(r->right);
    }
}
void inotra(AVLNode *r)//中序
{
    if(r){
        inotra(r->left);
        printf("<%d, %d> ",r->val,r->height);
        inotra(r->right);
    }
}
void tra(AVLNode *r){
    printf("pretra: ");
    pretra(r);
    printf("\n");
    printf("inotra: ");
    inotra(r);
    printf("\n");
}
int main()
{
    char op;
    int e;
    AVLNode *r=NULL;
    while(scanf("%c %d",&op,&e))
    {
        switch(op){
            case 'i':r=AVLinsert(r,e),tra(r);break;//插入e
            case 'r':r=AVLremove(r,e),tra(r);break;//删除e
            default:printf("error\n");break;
        }
        getchar();
    }
    return 0;
}
