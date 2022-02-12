/**
 * This header is generated by class-dump-z 0.2a.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: (null)
 */

typedef struct _NSZone NSZone;

/**
typedef struct CGPoint {
	float x;
	float y;
} CGPoint;

typedef struct CGSize {
	float width;
	float height;
} CGSize;

typedef struct CGRect {
	CGPoint origin;
	CGSize size;
} CGRect;*/

typedef struct b2Fixture b2Fixture;
typedef struct b2World b2World;
typedef struct b2JointEdge b2JointEdge;
typedef struct b2ContactEdge b2ContactEdge;

typedef struct b2Shape b2Shape;

typedef struct b2FixtureProxy b2FixtureProxy;

typedef struct b2Filter {
	unsigned short _field1;
	unsigned short _field2;
	short _field3;
} b2Filter;

typedef struct b2Vec2 {
	float x;
	float y;
} b2Vec2;

typedef struct b2Rot {
	float _field1;
	float _field2;
} b2Rot;

typedef struct b2Transform {
	b2Vec2 _field1;
	b2Rot _field2;
} b2Transform;

typedef struct b2Sweep {
	b2Vec2 _field1;
	b2Vec2 _field2;
	b2Vec2 _field3;
	float _field4;
	float _field5;
	float _field6;
} b2Sweep;

typedef struct b2Body {
	int _field1;
	unsigned short _field2;
	int _field3;
	b2Transform _field4;
	b2Sweep _field5;
	b2Vec2 _field6;
	float _field7;
	b2Vec2 _field8;
	float _field9;
	b2World* _field10;
	b2Body* _field11;
	b2Body* _field12;
	b2Fixture* _field13;
	int _field14;
	b2JointEdge* _field15;
	b2ContactEdge* _field16;
	float _field17;
	float _field18;
	float _field19;
	float _field20;
	float _field21;
	float _field22;
	float _field23;
	float _field24;
	void* _field25;
} b2Body;

struct b2Fixture {
	float _field1;
	b2Fixture* _field2;
	b2Body* _field3;
	b2Shape* _field4;
	float _field5;
	float _field6;
	b2FixtureProxy* _field7;
	int _field8;
	b2Filter _field9;
	bool _field10;
	void* _field11;
};

/**
typedef struct _NSRange {
	unsigned _field1;
	unsigned _field2;
} NSRange;
*/

typedef struct {
	unsigned long _field1;
	id* _field2;
	unsigned long* _field3;
	unsigned long _field4[5];
} XXStruct_kFm5bA;

typedef struct _ccColor3B {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} ccColor3B;

typedef struct _ccBlendFunc {
	unsigned src;
	unsigned dst;
} ccBlendFunc;

typedef struct ccColor4F {
	float r;
	float g;
	float b;
	float a;
} ccColor4F;

typedef struct b2Chunk b2Chunk;

typedef struct b2Block b2Block;

typedef struct b2BlockAllocator {
	b2Chunk* _field1;
	int _field2;
	int _field3;
	b2Block* _field4[14];
} b2BlockAllocator;

typedef struct b2StackEntry {
	char* _field1;
	int _field2;
	bool _field3;
} b2StackEntry;

typedef struct b2StackAllocator {
	BOOL _field1[102400];
	int _field2;
	int _field3;
	int _field4;
	b2StackEntry _field5[32];
	int _field6;
} b2StackAllocator;

typedef struct b2TreeNode b2TreeNode;

typedef struct b2DynamicTree {
	int _field1;
	b2TreeNode* _field2;
	int _field3;
	int _field4;
	int _field5;
	unsigned _field6;
	int _field7;
} b2DynamicTree;

typedef struct b2Pair b2Pair;

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

typedef struct b2Contact {
	/*function-pointer*/ void** _field1;
	float _field2;
	unsigned _field3;
	b2Contact* _field4;
	b2Contact* _field5;
	b2ContactEdge _field6;
	b2ContactEdge _field7;
	b2Fixture* _field8;
	b2Fixture* _field9;
	int _field10;
	int _field11;
	b2Manifold _field12;
	int _field13;
	float _field14;
	float _field15;
	float _field16;
	void* _field17;
} b2Contact;

typedef struct b2ContactFilter b2ContactFilter;

typedef struct b2ContactListener b2ContactListener;

typedef struct b2ContactManager {
	b2BroadPhase _field1;
	b2Contact* _field2;
	int _field3;
	b2ContactFilter* _field4;
	b2ContactListener* _field5;
	b2BlockAllocator* _field6;
} b2ContactManager;

typedef struct b2Joint {
	/*function-pointer*/ void** _field1;
	int _field2;
	b2Joint* _field3;
	b2Joint* _field4;
	b2JointEdge _field5;
	b2JointEdge _field6;
	b2Body* _field7;
	b2Body* _field8;
	int _field9;
	bool _field10;
	bool _field11;
	void* _field12;
} b2Joint;

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

typedef struct GLESDebugDraw {
	/*function-pointer*/ void** _field1;
	unsigned _field2;
	float _field3;
	id _field4;
	int _field5;
} GLESDebugDraw;

typedef struct HSB2RaycastListener {
	/*function-pointer*/ void** _field1;
	id _field2;
} HSB2RaycastListener;

typedef struct GhostPoint {
	float x;
	float y;
} GhostPoint;

typedef struct ghostData {
	float ts;
	GhostPoint pos;
	float rot;
	float Object248;
	unsigned Object200 : 1;
	unsigned friction : 1;
	unsigned rocket : 1;
	unsigned animation : 4;
	unsigned left : 1;
	unsigned right : 1;
} ghostData;

typedef struct b2Rot {
	float _field1;
	float _field2;
} b2Rot;


struct b2JointEdge {
	b2Body* _field1;
	b2Joint* _field2;
	b2JointEdge* _field3;
	b2JointEdge* _field4;
};

struct b2ContactEdge {
	b2Body* _field1;
	b2Contact* _field2;
	b2ContactEdge* _field3;
	b2ContactEdge* _field4;
};

typedef struct b2Vec3 {
	float _field1;
	float _field2;
	float _field3;
} b2Vec3;

typedef struct b2Mat33 {
	b2Vec3 _field1;
	b2Vec3 _field2;
	b2Vec3 _field3;
} b2Mat33;

typedef struct b2RevoluteJoint {
	/*function-pointer*/ void** _field1;
	int _field2;
	b2Joint* _field3;
	b2Joint* _field4;
	b2JointEdge _field5;
	b2JointEdge _field6;
	b2Body* _field7;
	b2Body* _field8;
	int _field9;
	bool _field10;
	bool _field11;
	void* _field12;
	b2Vec2 _field13;
	b2Vec2 _field14;
	b2Vec3 _field15;
	float _field16;
	bool _field17;
	float _field18;
	float _field19;
	bool _field20;
	float _field21;
	float _field22;
	float _field23;
	int _field24;
	int _field25;
	b2Vec2 _field26;
	b2Vec2 _field27;
	b2Vec2 _field28;
	b2Vec2 _field29;
	float _field30;
	float _field31;
	float _field32;
	float _field33;
	b2Mat33 _field34;
	float _field35;
	int _field36;
} b2RevoluteJoint;

typedef struct b2ContactFeature {
	unsigned char _field1;
	unsigned char _field2;
	unsigned char _field3;
	unsigned char _field4;
} b2ContactFeature;

typedef union b2ContactID {
	b2ContactFeature _field1;
	unsigned _field2;
} b2ContactID;

typedef struct b2ManifoldPoint {
	b2Vec2 _field1;
	float _field2;
	float _field3;
	b2ContactID _field4;
} b2ManifoldPoint;

typedef struct b2Manifold {
	b2ManifoldPoint _field1[2];
	b2Vec2 _field2;
	b2Vec2 _field3;
	int _field4;
	int _field5;
} b2Manifold;

typedef struct __CFSocket* CFSocketRef;

typedef struct __CFRunLoopSource* CFRunLoopSourceRef;

typedef struct b2Mat22 {
	b2Vec2 _field1;
	b2Vec2 _field2;
} b2Mat22;

typedef struct b2MouseJoint {
	/*function-pointer*/ void** _field1;
	int _field2;
	b2Joint* _field3;
	b2Joint* _field4;
	b2JointEdge _field5;
	b2JointEdge _field6;
	b2Body* _field7;
	b2Body* _field8;
	int _field9;
	bool _field10;
	bool _field11;
	void* _field12;
	b2Vec2 _field13;
	b2Vec2 _field14;
	float _field15;
	float _field16;
	float _field17;
	b2Vec2 _field18;
	float _field19;
	float _field20;
	int _field21;
	int _field22;
	b2Vec2 _field23;
	b2Vec2 _field24;
	float _field25;
	float _field26;
	b2Mat22 _field27;
	b2Vec2 _field28;
} b2MouseJoint;

typedef struct b2FixtureDef {
	b2Shape* _field1;
	void* _field2;
	float _field3;
	float _field4;
	float _field5;
	bool _field6;
	b2Filter _field7;
} b2FixtureDef;

typedef struct _ccVertex3F {
	float x;
	float y;
	float z;
} ccVertex3F;

typedef struct _ccColor4B {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} ccColor4B;

typedef struct _ccTex2F {
	float u;
	float v;
} ccTex2F;

typedef struct _ccV3F_C4B_T2F {
	ccVertex3F vertices;
	ccColor4B colors;
	ccTex2F texCoords;
} ccV3F_C4B_T2F;

typedef struct _ccV3F_C4B_T2F_Triangle {
	ccV3F_C4B_T2F _field1;
	ccV3F_C4B_T2F _field2;
	ccV3F_C4B_T2F _field3;
} ccV3F_C4B_T2F_Triangle;

typedef struct b2ContactImpulse {
	float _field1[2];
	float _field2[2];
	int _field3;
} b2ContactImpulse;

typedef struct UT_hash_table UT_hash_table;

typedef struct UT_hash_handle {
	UT_hash_table* _field1;
	void* _field2;
	void* _field3;
	UT_hash_handle* _field4;
	UT_hash_handle* _field5;
	void* _field6;
	unsigned _field7;
	unsigned _field8;
} UT_hash_handle;

typedef struct _contactNodeElement {
	UT_hash_handle _field1;
	int _field2;
	id _field3;
	SEL _field4;
} contactNodeElement;

typedef struct _collisionMapElement {
	UT_hash_handle _field1;
	int _field2;
	contactNodeElement* _field3;
} collisionMapElement;

typedef struct LHContactListener {
	/*function-pointer*/ void** _field1;
	void* _field2;
	/*function-pointer*/ void* _field3;
	/*function-pointer*/ void* _field4;
	/*function-pointer*/ void* _field5;
} LHContactListener;

template<>
struct __compressed_pair<CGPoint *, std::__1::allocator<CGPoint> > {
	CGPoint* __first_;
};

template<>
struct vector<CGPoint, std::__1::allocator<CGPoint> > {
	CGPoint* __begin_;
	CGPoint* __end_;
	__compressed_pair<CGPoint *, std::__1::allocator<CGPoint> > __end_cap_;
};

template<>
struct __compressed_pair<b2Vec2 *, std::__1::allocator<b2Vec2> > {
	b2Vec2* _field1;
};

template<>
struct vector<b2Vec2, std::__1::allocator<b2Vec2> > {
	b2Vec2* _field1;
	b2Vec2* _field2;
	__compressed_pair<b2Vec2 *, std::__1::allocator<b2Vec2> > _field3;
};

typedef struct __CFRunLoop* CFRunLoopRef;

typedef struct __CFString* CFStringRef;

typedef struct {
	int _field1;
	void* _field2;
	/*function-pointer*/ void* _field3;
	/*function-pointer*/ void* _field4;
	/*function-pointer*/ void* _field5;
} XXStruct_K1psTC;

typedef struct JKHashTableEntry {
	unsigned _field1;
	id _field2;
	id _field3;
} JKHashTableEntry;

typedef struct JKConstPtrRange {
	char* _field1;
	unsigned _field2;
} JKConstPtrRange;

typedef struct JKConstBuffer {
	JKConstPtrRange _field1;
} JKConstBuffer;

typedef struct JKTokenCacheItem* JKTokenCacheItemRef;

typedef struct JKTokenValue {
	JKConstPtrRange _field1;
	unsigned _field2;
	unsigned _field3;
	union {
		long long _field1;
		unsigned long long _field2;
		double _field3;
	} _field4;
	JKTokenCacheItemRef _field5;
} JKTokenValue;

typedef struct JKPtrRange {
	char* _field1;
	unsigned _field2;
} JKPtrRange;

typedef struct JKManagedBuffer {
	JKPtrRange _field1;
	unsigned _field2;
	unsigned _field3;
} JKManagedBuffer;

typedef struct JKParseToken {
	JKConstPtrRange _field1;
	unsigned _field2;
	JKTokenValue _field3;
	JKManagedBuffer _field4;
} JKParseToken;

typedef struct JKObjectStack {
	void** _field1;
	void** _field2;
	unsigned* _field3;
	unsigned _field4;
	unsigned _field5;
	unsigned _field6;
	unsigned _field7;
} JKObjectStack;

typedef struct JKTokenCache {
	JKTokenCacheItemRef _field1;
	unsigned _field2;
	unsigned _field3;
	unsigned char _field4[1024];
} JKTokenCache;

typedef struct JKObjCImpCache {
	Class _field1;
	/*function-pointer*/ void* _field2;
	/*function-pointer*/ void* _field3;
} JKObjCImpCache;

typedef struct JKParseState {
	unsigned _field1;
	JKConstBuffer _field2;
	unsigned _field3;
	unsigned _field4;
	unsigned _field5;
	unsigned _field6;
	unsigned _field7;
	unsigned _field8;
	JKParseToken _field9;
	JKObjectStack _field10;
	JKTokenCache _field11;
	JKObjCImpCache _field12;
	id _field13;
	int _field14;
	BOOL _field15;
} JKParseState;

typedef struct JKFastClassLookup {
	void* _field1;
	void* _field2;
	void* _field3;
	void* _field4;
	void* _field5;
} JKFastClassLookup;

typedef struct JKEncodeCache {
	id _field1;
	unsigned _field2;
	unsigned _field3;
} JKEncodeCache;

typedef struct JKEncodeState {
	JKManagedBuffer _field1;
	JKManagedBuffer _field2;
	unsigned _field3;
	JKFastClassLookup _field4;
	JKEncodeCache _field5[1024];
	unsigned _field6;
	unsigned _field7;
	unsigned _field8;
	id _field9;
	id _field10;
	SEL _field11;
	/*function-pointer*/ void* _field12;
	id _field13;
	/*function-pointer*/ void _field14;
} JKEncodeState;

typedef struct _ccGridSize {
	int x;
	int y;
} ccGridSize;

typedef struct _ccQuad3 {
	ccVertex3F _field1;
	ccVertex3F _field2;
	ccVertex3F _field3;
	ccVertex3F _field4;
} ccQuad3;

typedef struct _ccBezierConfig {
	CGPoint endPosition;
	CGPoint controlPoint_1;
	CGPoint controlPoint_2;
} ccBezierConfig;

typedef struct ccArray {
	unsigned _field1;
	unsigned _field2;
	id* _field3;
} ccArray;

typedef struct _hashElement {
	ccArray* _field1;
	unsigned _field2;
	BOOL _field3;
	BOOL _field4;
	UT_hash_handle _field5;
	id _field6;
	id _field7;
} hashElement;

typedef struct {
	CGPoint _field1;
	CGPoint _field2;
	ccGridSize _field3;
} XXStruct_zekEVB;

typedef struct kmMat4 {
	float mat[16];
} kmMat4;

typedef struct timeval {
	int tv_sec;
	int tv_usec;
} timeval;

typedef struct _hashUniformEntry {
	void* _field1;
	unsigned _field2;
	UT_hash_handle _field3;
} hashUniformEntry;

typedef struct _BMFontDef {
	unsigned short _field1;
	CGRect _field2;
	short _field3;
	short _field4;
	short _field5;
} BMFontDef;

typedef struct _FontDefHashElement {
	unsigned _field1;
	BMFontDef _field2;
	UT_hash_handle _field3;
} FontDefHashElement;

typedef struct _BMFontPadding {
	int left;
	int top;
	int right;
	int bottom;
} BMFontPadding;

typedef struct _KerningHashElement {
	int _field1;
	int _field2;
	UT_hash_handle _field3;
} KerningHashElement;

typedef struct _ccVertex2F {
	float x;
	float y;
} ccVertex2F;

typedef struct CGAffineTransform {
	float a;
	float b;
	float c;
	float d;
	float tx;
	float ty;
} CGAffineTransform;

typedef struct sCCParticle {
	CGPoint _field1;
	CGPoint _field2;
	ccColor4F _field3;
	ccColor4F _field4;
	float _field5;
	float _field6;
	float _field7;
	float _field8;
	float _field9;
	unsigned _field10;
	union {
		struct {
			CGPoint _field1;
			float _field2;
			float _field3;
		} _field1;
		ccColor4F _field2;
	} _field11;
} sCCParticle;

typedef struct _ccV3F_C4B_T2F_Quad {
	ccV3F_C4B_T2F tl;
	ccV3F_C4B_T2F bl;
	ccV3F_C4B_T2F tr;
	ccV3F_C4B_T2F br;
} ccV3F_C4B_T2F_Quad;

typedef struct _ccV2F_C4B_T2F {
	ccVertex2F _field1;
	ccColor4B _field2;
	ccTex2F _field3;
} ccV2F_C4B_T2F;

typedef struct CGImage* CGImageRef;

typedef struct _listEntry {
	listEntry* _field1;
	listEntry* _field2;
	/*function-pointer*/ void* _field3;
	id _field4;
	int _field5;
	BOOL _field6;
	BOOL _field7;
} listEntry;

typedef struct _hashUpdateEntry {
	listEntry** _field1;
	listEntry* _field2;
	id _field3;
	UT_hash_handle _field4;
} hashUpdateEntry;

typedef struct _hashSelectorEntry {
	ccArray* _field1;
	id _field2;
	unsigned _field3;
	id _field4;
	BOOL _field5;
	BOOL _field6;
	UT_hash_handle _field7;
} hashSelectorEntry;

typedef struct _ccTexParams {
	unsigned _field1;
	unsigned _field2;
	unsigned _field3;
	unsigned _field4;
} ccTexParams;

typedef struct CCPVRMipmap {
	char* address;
	unsigned len;
} CCPVRMipmap;

typedef struct sImageTGA {
	int _field1;
	unsigned char _field2;
	unsigned char _field3;
	short _field4;
	short _field5;
	char* _field6;
	int _field7;
} sImageTGA;

typedef struct ccTouchHandlerHelperData {
	SEL touchesSel;
	SEL touchSel;
	int type;
} ccTouchHandlerHelperData;

typedef struct _bufferInfo {
	unsigned _field1;
	int _field2;
	void* _field3;
	int _field4;
	int _field5;
	int _field6;
} bufferInfo;

typedef struct _sourceInfo {
	bool _field1;
	unsigned _field2;
	unsigned _field3;
} sourceInfo;

typedef struct _sourceGroup {
	int _field1;
	int _field2;
	int _field3;
	bool _field4;
	bool _field5;
	int* _field6;
} sourceGroup;

typedef struct ALCcontext_struct* ALCcontext_structRef;

typedef struct b2DistanceJoint {
	/*function-pointer*/ void** _field1;
	int _field2;
	b2Joint* _field3;
	b2Joint* _field4;
	b2JointEdge _field5;
	b2JointEdge _field6;
	b2Body* _field7;
	b2Body* _field8;
	int _field9;
	bool _field10;
	bool _field11;
	void* _field12;
	float _field13;
	float _field14;
	float _field15;
	b2Vec2 _field16;
	b2Vec2 _field17;
	float _field18;
	float _field19;
	float _field20;
	int _field21;
	int _field22;
	b2Vec2 _field23;
	b2Vec2 _field24;
	b2Vec2 _field25;
	b2Vec2 _field26;
	b2Vec2 _field27;
	float _field28;
	float _field29;
	float _field30;
	float _field31;
	float _field32;
} b2DistanceJoint;

typedef struct linePoint {
	CGPoint _field1;
	BOOL _field2;
} linePoint;

typedef struct __SCNetworkReachability* SCNetworkReachabilityRef;

typedef struct {
	SCNetworkReachabilityRef reachabilityRef;
	BOOL started;
	BOOL connectionRequired;
	BOOL reachable;
	BOOL reachableViaWiFi;
	BOOL reachableViaWWAN;
	BOOL isLocalWiFi;
} XXStruct_ecqpFB;

typedef struct b2PrismaticJoint {
	/*function-pointer*/ void** _field1;
	int _field2;
	b2Joint* _field3;
	b2Joint* _field4;
	b2JointEdge _field5;
	b2JointEdge _field6;
	b2Body* _field7;
	b2Body* _field8;
	int _field9;
	bool _field10;
	bool _field11;
	void* _field12;
	b2Vec2 _field13;
	b2Vec2 _field14;
	b2Vec2 _field15;
	b2Vec2 _field16;
	float _field17;
	b2Vec3 _field18;
	float _field19;
	float _field20;
	float _field21;
	float _field22;
	float _field23;
	bool _field24;
	bool _field25;
	int _field26;
	int _field27;
	int _field28;
	b2Vec2 _field29;
	b2Vec2 _field30;
	float _field31;
	float _field32;
	float _field33;
	float _field34;
	b2Vec2 _field35;
	b2Vec2 _field36;
	float _field37;
	float _field38;
	float _field39;
	float _field40;
	b2Mat33 _field41;
	float _field42;
} b2PrismaticJoint;

typedef struct __SecTrust SecTrust;

typedef struct _ccFontShadow {
	bool m_shadowEnabled;
	CGSize m_shadowOffset;
	float m_shadowBlur;
	float m_shadowOpacity;
} ccFontShadow;

typedef struct _ccFontStroke {
	bool m_strokeEnabled;
	ccColor3B m_strokeColor;
	float m_strokeSize;
} ccFontStroke;

typedef struct CGPath* CGPathRef;

typedef struct UIEdgeInsets {
	float _field1;
	float _field2;
	float _field3;
	float _field4;
} UIEdgeInsets;

typedef struct FBSDKLikeControlLayout {
	CGSize _field1;
	CGRect _field2;
	CGRect _field3;
} FBSDKLikeControlLayout;

typedef struct __SecCertificate SecCertificate;

typedef struct {
	unsigned major;
	unsigned minor;
	unsigned bugfix;
} XXStruct_VQhNEA;

typedef struct CLSMachOFile {
	int fd;
	unsigned mappedSize;
	void* mappedFile;
} CLSMachOFile;

typedef struct CLSMachOSlice {
	void* startAddress;
	int cputype;
	int cpusubtype;
} CLSMachOSlice;

typedef struct {
	int _field1;
	int _field2;
	int _field3;
} XXStruct_peQPEB;

typedef struct __SecRandom SecRandom;

typedef struct {
	BOOL _field1[33];
	bool _field2;
	XXStruct_VQhNEA _field3;
	XXStruct_VQhNEA _field4;
	struct {
		void* _field1;
		unsigned long long _field2;
		void* _field3;
	} _field5;
	CLSMachOSlice _field6;
	int _field7;
} XXStruct_sUoPdA;

typedef struct {
	char* _field1;
	void* _field2;
	bool _field3;
	void* _field4;
	char* _field5;
	char* _field6;
	char* _field7;
	char* _field8;
	char* _field9;
	unsigned _field10;
	bool _field11;
	bool _field12;
	unsigned _field13;
	unsigned _field14;
	unsigned _field15;
	unsigned _field16;
} XXStruct_69FNmD;

typedef struct {
	char* _field1;
	char* _field2;
	unsigned _field3;
	unsigned _field4;
} XXStruct_aQabGB;


