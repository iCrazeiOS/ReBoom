typedef struct b2World b2World;
typedef struct b2Chunk b2Chunk;

typedef struct b2Block b2Block;
typedef struct b2Body b2Body;
typedef struct b2Joint b2Joint;
typedef struct b2Contact b2Contact;
typedef struct b2BroadPhase b2BroadPhase;
typedef struct b2DynamicTree b2DynamicTree;
typedef struct b2ContactFilter b2ContactFilter;
//typedef struct b2ContactManager b2ContactManager;

typedef struct b2BlockAllocator b2BlockAllocator;
typedef struct b2Pair b2Pair;
typedef struct b2TreeNode b2TreeNode;
typedef struct b2ContactListener b2ContactListener;
typedef struct b2DestructionListener b2DestructionListener;
typedef struct b2Draw b2Draw;

typedef struct b2Profile {
	float _field1;
	float _field2;
	float _field3;
	float _field4;
	float _field5;
	float _field6;
	float _field7;
	float _field8;
} b2Profile;

typedef struct b2DynamicTree {
	int _field1;
	b2TreeNode* _field2;
	int _field3;
	int _field4;
	int _field5;
	unsigned _field6;
	int _field7;
} b2DynamicTree;

typedef struct b2BroadPhase {
	b2DynamicTree _field1;
	int _field2;
	int* _field3;
	int _field4;
	int _field5;
	b2Pair* _field6;
	int _field7;
	int _field8;
	int _field9;
} b2BroadPhase;

typedef struct b2Vec3 {
	float _field1;
	float _field2;
	float _field3;
} b2Vec3;


typedef struct b2Vec2 {
	float x;
	float y;
} b2Vec2;

typedef struct b2StackEntry {
	char* _field1;
	int _field2;
	bool _field3;
} b2StackEntry;

// typedef struct b2Contact {
// 	//*function-pointer*/ void** _field1;
// 	float _field2;
// 	unsigned _field3;
// 	b2Contact* _field4;
// 	b2Contact* _field5;
// 	b2ContactEdge _field6;
// 	b2ContactEdge _field7;
// 	b2Fixture* _field8;
// 	b2Fixture* _field9;
// 	int _field10;
// 	int _field11;
// 	b2Manifold _field12;
// 	int _field13;
// 	float _field14;
// 	float _field15;
// 	float _field16;
// 	void* _field17;
// } b2Contact;


typedef struct b2ContactManager {
	b2BroadPhase _field1;
	b2Contact* _field2;
	int _field3;
	b2ContactFilter* _field4;
	b2ContactListener* _field5;
	b2BlockAllocator* _field6;
} b2ContactManager;

typedef struct b2StackAllocator {
	BOOL _field1[102400];
	int _field2;
	int _field3;
	int _field4;
	b2StackEntry _field5[32];
	int _field6;
} b2StackAllocator;

typedef struct b2BlockAllocator {
	b2Chunk* _field1;
	int _field2;
	int _field3;
	b2Block* _field4[14];
} b2BlockAllocator;

struct b2World {
	b2BlockAllocator _field1;
	b2StackAllocator _field2;
	int _field3;
	b2ContactManager _field4;
	b2Body* _field5;
	b2Joint* _field6;
	int _field7;
	int _field8;
	b2Vec2 _field9;
	bool _field10;
	b2DestructionListener* _field11;
	b2Draw* _field12;
	float _field13;
	bool _field14;
	bool _field15;
	bool _field16;
	bool _field17;
	b2Profile _field18;
};