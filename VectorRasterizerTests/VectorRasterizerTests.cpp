#include "pch.h"
#include "CppUnitTest.h"
#include "XMLDataLoaderAdapterTest.hpp"
#include "XMLDataLoaderAdapter.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VectorRasterizerTests
{
	TEST_CLASS(VectorRasterizerTests)
	{
	public:
		
        TEST_METHOD(TestLoadPolygon)
        {
            XMLDataLoaderAdapterTest::TestLoadPolygon();
        }

        TEST_METHOD(TestLoadCircle)
        {
            XMLDataLoaderAdapterTest::TestLoadCircle();
        }

        TEST_METHOD(TestLoadLine)
        {
            XMLDataLoaderAdapterTest::TestLoadLine();
        }

        TEST_METHOD(TestLoadCurve)
        {
            XMLDataLoaderAdapterTest::TestLoadCurve();
        }
	};
}
