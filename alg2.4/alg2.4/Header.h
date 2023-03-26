//RBTNode.h
enum RBTColor { Black, Red };

template<class KeyType>
struct  RBTNode
{
	KeyType key;
	RBTColor color;
	RBTNode<KeyType>* left;
	RBTNode<KeyType>* right;
	RBTNode<KeyType>* parent;
	RBTNode(KeyType k, RBTColor c, RBTNode* p, RBTNode* l, RBTNode* r) :
		key(k), color(c), parent(p), left(l), right(r) { };
}; 
