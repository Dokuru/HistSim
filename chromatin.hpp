/*
 * chromatin.hpp
 *
 *  Created on: Apr 23, 2015
 *      Author: nicoh
 */

#ifndef CHROMATIN_HPP_
#define CHROMATIN_HPP_

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include "nucleosome.hpp"


class chromatin
{
	public:
		chromatin(boost::variant<std::string, int> iNumNucleosomes_, boost::variant<std::string, int> sInitialState_, boost::variant<std::string, int> iIsCyclic_, std::vector<int> aOriPos_ );
		virtual ~chromatin();
		std::vector<cNucleosome> mInitNucleosomes(boost::variant<std::string, int> sInitialState_);
		void mPrintInfo();
	//private:
		int iNumNucleosomes;
		std::vector<cNucleosome*> aNucleosomes; //pointers of nucleosome objects
		int iIsCyclic;
		std::vector<int> aOrigins;
};

#endif /* CHROMATIN_HPP_ */
