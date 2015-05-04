/*
 * nucleosome.hpp
 *
 *  Created on: Apr 23, 2015
 *      Author: nicoh
 */

#ifndef NUCLEOSOME_HPP_
#define NUCLEOSOME_HPP_

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include "helper.hpp"
#include <boost/lexical_cast.hpp>

class cNucleosome
{
	public:
		cNucleosome(int iPosition_, std::string sHistoneStates_);
		virtual ~cNucleosome();

	//private:
		int iPosition;
		std::map< std::string, std::map<int, int> > mModifications;


};

#endif /* NUCLEOSOME_HPP_ */
