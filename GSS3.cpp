#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
 
const int maxn = 50050;
int n, m, x, y, op, val[maxn];
 
struct SegNode {
	int left, right, sum, maxLeft, maxRight, maxAll;
	int mid() { return (left + right) >> 1; }
};
 
struct SegmentTree {
 
	SegNode tree[maxn*5];
 
	SegNode pushUp(SegNode left, SegNode right) {
		SegNode update;
		update.sum = left.sum + right.sum;
		update.maxLeft = max(left.maxLeft, left.sum + right.maxLeft);
		update.maxRight = max(right.maxRight, right.sum + left.maxRight);
		update.maxAll = max(max(left.maxAll, right.maxAll), left.maxRight + right.maxLeft);
		return update;
	}
 
	void build(int left, int right, int idx) {
		tree[idx].left = left; tree[idx].right = right;
		if (left == right) {
			tree[idx].sum = tree[idx].maxLeft = tree[idx].maxRight = tree[idx].maxAll = val[left];
			return ;
		}
		int mid = tree[idx].mid();
		build(left, mid, idx<<1); build(mid+1, right, idx<<1|1);
		SegNode update = pushUp(tree[idx<<1], tree[idx<<1|1]);
		tree[idx].sum = update.sum; tree[idx].maxLeft = update.maxLeft;
		tree[idx].maxRight = update.maxRight; tree[idx].maxAll = update.maxAll;
	}
 
	void update(int pos, int value, int idx) {
		if (tree[idx].left == tree[idx].right) {
			tree[idx].maxAll = value; tree[idx].sum = value; tree[idx].maxLeft = value;
			tree[idx].maxRight = value; return ;
		}
		int mid = tree[idx].mid();
		if (pos <= mid) update(pos, value, idx<<1);
		else update(pos, value, idx<<1|1);
		SegNode update = pushUp(tree[idx<<1], tree[idx<<1|1]);
		tree[idx].sum = update.sum; tree[idx].maxLeft = update.maxLeft;
		tree[idx].maxRight = update.maxRight; tree[idx].maxAll = update.maxAll;
	}
 
	SegNode query(int left, int right, int idx) {
		if (tree[idx].left >= left && tree[idx].right <= right)
			return tree[idx];
		int mid = tree[idx].mid();
		if (right <= mid) return query(left, right, idx<<1);
		else if (left > mid) return query(left, right, idx<<1|1);
		else return pushUp(query(left, mid, idx<<1), query(mid+1, right, idx<<1|1));
	}
};
 
SegmentTree seg;
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", val + i);
	seg.build(1, n, 1); scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &op, &x, &y);
		if (op == 1) printf("%d\n", seg.query(x, y, 1).maxAll);
		else seg.update(x, y, 1);
	}
	return 0;
}
 
