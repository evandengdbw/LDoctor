#ifndef _H_SONGLH_WORKLESS
#define _H_SONGLH_WORKLESS

#include "llvm/Pass.h"
#include "llvm/Transforms/Utils/ValueMapper.h"

#include <string>
#include <set>
#include <vector>

using namespace llvm;
using namespace std;

struct WorklessInstrument : public ModulePass
{
	static char ID;
	WorklessInstrument();
	virtual void getAnalysisUsage(AnalysisUsage &AU) const;
	virtual bool runOnModule(Module& M);
	virtual void print(raw_ostream &O, const Module *M) const;	


	void SetupTypes(Module * );
	void SetupConstants(Module * pModule);
	void SetupHooks(Module * );
	void SetupGlobals(Module * pModule);

	void ParseWorkingBlocks(set<string> & setWorkingBlocks);

	void CreateIfElseBlock(Loop * pLoop, vector<BasicBlock *> & vecAdded);
	void RemapInstruction(Instruction *I, ValueToValueMapTy &VMap); 
	void CloneInnerLoop(Loop * pLoop, vector<BasicBlock *> & vecAdd, ValueToValueMapTy & VMap, set<BasicBlock *> & setCloned);

	void InstrumentWorkless0Star1(Module * pModule, Loop * pLoop);
	void InstrumentWorkless0Or1Star(Module * pModule, Loop * pLoop, set<string> & setWorkingBlocks);

//type
	IntegerType *CharType ;
	IntegerType *BoolType ;
	IntegerType *LongType ;
	IntegerType *IntType  ;
	PointerType *CharStarType ;
	Type * VoidType ;
	Type * VoidPointerType;


//function
	Function * PrintLoopInfo;
	Function * PrintWorkingRatio ;
	Function * getenv;
	Function * function_atoi;
	Function * printf;
	Function * geo;
	Function * func_llvm_memcpy;
	Function * InitHooks;

//globalvariable
	GlobalVariable * numIterations;
	GlobalVariable * numInstances ;
	GlobalVariable * numWorkingIterations ;
	GlobalVariable * bWorkingIteration ;

	GlobalVariable * SAMPLE_RATE;
	GlobalVariable * numGlobalCounter;
	GlobalVariable * PC_SAMPLE_RATE;
	GlobalVariable * CURRENT_SAMPLE;


	Constant * SAMPLE_RATE_ptr;
	Constant * Output_Format_String;

//constants
	ConstantInt * ConstantInt0;
	ConstantInt * ConstantInt1;
	ConstantInt * ConstantInt2;
	ConstantInt * ConstantInt3;
	ConstantInt * ConstantInt4;
	ConstantInt * ConstantInt10;
	ConstantInt * ConstantInt32;
	ConstantInt * ConstantInt_1;

	ConstantInt * ConstantLong_1;
	ConstantInt * ConstantLong0;
	ConstantInt * ConstantLong1;

	ConstantInt * ConstantCharFalse;
	ConstantInt * ConstantCharTrue;

	ConstantInt * ConstantBoolFalse;
	ConstantInt * ConstantBoolTrue;

	
	ConstantPointerNull * ConstantNULL;


	//global


};

#endif

