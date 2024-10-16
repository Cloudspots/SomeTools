#include "huffmancode.h" //huffmancode的声明
#include <queue>

using namespace std;

_BEGIN_TOOLS

class hfc_treenode
{
public:
	string name;
	int cnt;
	hfc_treenode* l = nullptr, * r = nullptr;
};

class hfctless //自定义小于
{
public:
	bool operator()(const hfc_treenode *x, const hfc_treenode *y) const { return x->cnt > y->cnt; }
};

static void dfs(hfc_treenode* root, unordered_map<string, string>& gans, string pth)
{
	//printf("root = %p = {%s, %d, %p, %p}\n", root, root->name.c_str(), root->cnt, root->l, root->r);
	if (root->l == root->r && root->l == nullptr)
	{
		gans[root->name] = pth;
		delete root;
		return;
	}
	dfs(root->l, gans, pth + "0");
	dfs(root->r, gans, pth + "1");
	delete root;
}

unordered_map<string, string> huffmancode(unordered_map<string, int> strs)
{
	priority_queue<hfc_treenode *, vector<hfc_treenode *>, hfctless> pq;
	for (pair<string, int> u : strs)
	{
		//printf("%s\t%d\n", u.first.c_str(), u.second);
		hfc_treenode* tmp = new hfc_treenode{ u.first, u.second, nullptr, nullptr };
		pq.push(tmp);
		//printf("%p<->%p\n", tmp, pq.top());
	}
	while (pq.size() > 1)
	{
		hfc_treenode* u1 = pq.top();
		pq.pop();
		hfc_treenode *u2 = pq.top();
		pq.pop();
		//printf("u1 = %p = {%s\t%d\t%p\t%p}\nu2 = %p = {%s\t%d\t%p\t%p}\n", u1, u1->name.c_str(), u1->cnt, u1->l, u1->r, u2, u2->name.c_str(), u2->cnt, u2->l, u2->r);;
		hfc_treenode *v = new hfc_treenode{ u1->name + u2->name, u1->cnt + u2->cnt, u1, u2 };
		pq.push(v);
	}
	unordered_map<string, string> ans;
	hfc_treenode* root = pq.top();
	dfs(root, ans, "");
	return ans;
}

_END_TOOLS