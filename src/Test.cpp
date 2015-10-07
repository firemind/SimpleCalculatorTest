#include <SimpleCalculator.cpp>
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <iostream>


void testForAddition() {
	ASSERT_EQUAL(  12, calc(9,3,'+'));
	ASSERT_EQUAL(   6, calc(9,-3,'+'));
	ASSERT_EQUAL( -12, calc(-9,-3,'+'));
	ASSERT_EQUAL(   3, calc(0,3,'+'));
}

void testForSubstraction() {
	ASSERT_EQUAL( 6, calc(9,3,'-'));
	ASSERT_EQUAL( 12, calc(9,-3,'-'));
}
void testForMultiplication() {
	ASSERT_EQUAL(27, calc(9,3,'*'));
	ASSERT_EQUAL(12, calc(2,6,'*'));
}
void testForDivision() {
	ASSERT_EQUAL(3,  calc(9,3,'/'));
	ASSERT_EQUAL(2,  calc(16,8,'/'));
}
void testForModulo() {
	ASSERT_EQUAL(1, calc(9,2,'%'));
	ASSERT_EQUAL(2, calc(11,3,'%'));

}
void testForInvalidArguments() {

	ASSERT_THROWSM("division by zero", calc(9,0,'/'), std::invalid_argument );
	ASSERT_THROWSM("modulo by zero", calc(9,0,'%'), std::invalid_argument );
	ASSERT_THROWSM("not a valid operator ?", calc(9,0,'?'), std::invalid_argument );

}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testForAddition));
	s.push_back(CUTE(testForSubstraction));
	s.push_back(CUTE(testForMultiplication));
	s.push_back(CUTE(testForDivision));
	s.push_back(CUTE(testForInvalidArguments));
	s.push_back(CUTE(testForModulo));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



