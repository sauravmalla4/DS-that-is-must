#include<iostream>
#include<unordered_map>
using namespace std;


class DSUNode{
public:
	DSUNode *parent;
	int rank;
	int val;
	DSUNode(int val){
		this->rank=0;
		this->val=val;
	}
};


unordered_map<int,DSUNode*> ump;

void makeset(int val){
	DSUNode *d=new DSUNode(val);
	d->parent=d;
	ump[val]=d;
}

DSUNode* findRep(DSUNode *d){
	DSUNode *parent=d->parent;
	if(parent==d){
		return d;
	}
	d->parent=findRep(parent);
	return d->parent;
}


bool _union(int val1,int val2){
	DSUNode *d1=ump[val1];
	DSUNode *d2=ump[val2];
	
	DSUNode *parent1=findRep(d1);
	DSUNode *parent2=findRep(d2);
	
	if(parent1->val==parent2->val){
		return false;
	}
	
	if(parent1->rank>=parent2->rank){
		parent1->rank+=(parent1->rank==parent2->rank)?1:0;
		parent2->parent=parent1;
	}
	else{
		parent1->parent=parent2;
	}
	return true;
}

int main(){
	makeset(1);
	makeset(2);
	makeset(3);
	makeset(4);
	makeset(5);
	
	_union(1,3);
	_union(2,4);
	
	cout<<findRep(ump[4])->val<<endl;
	
	_union(1,4);
	_union(1,5);
	
	cout<<findRep(ump[1])->val<<endl;
	cout<<findRep(ump[2])->val<<endl;
	cout<<findRep(ump[3])->val<<endl;
	cout<<findRep(ump[4])->val<<endl;
	cout<<findRep(ump[5])->val<<endl;
	
	return 0;
}
	
