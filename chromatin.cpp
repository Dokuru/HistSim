/*
 * chromatin.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: nicoh
 */

#include "chromatin.hpp"
#include "helper.hpp"
#include <boost/lexical_cast.hpp>
#include <vector>
#include <boost/variant/variant.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/algorithm/copy.hpp>

chromatin::chromatin(boost::variant<std::string, int> iNumNucleosomes_, boost::variant<std::string, int> sInitialState_, boost::variant<std::string, int> iIsCyclic_, std::vector<int> aOriPos_ )
{
	iNumNucleosomes = boost::lexical_cast<int>(iNumNucleosomes_);
	iIsCyclic = boost::lexical_cast<int>(iIsCyclic_);


	std::vector<cNucleosome*> tmp;

	tmp = mInitNucleosomes(sInitialState_);
	aNucleosomes = tmp;

	aOrigins = aOriPos_;

}

chromatin::~chromatin()
{
	// TODO: destructor
}

std::vector<cNucleosome> chromatin::mInitNucleosomes(boost::variant<std::string, int> sInitialState_)
{



	std::vector<cNucleosome*> aNucleosomeVector;

	std::vector<std::string> nucleosomelevel = explode(boost::lexical_cast<std::string>(sInitialState_),"|");

	for(unsigned int i = 0; i <= nucleosomelevel.size(); ++i)
	{



		aNucleosomeVector[i] = new cNucleosome(i, nucleosomelevel[i]);
		std::cout << i << "... \n";
	}


	return aNucleosomeVector;

}

void chromatin::mPrintInfo()
{
	std::cout << "Info: \n number of nucleosomes: " << iNumNucleosomes << "\n \nStatus of nucleosomes: \n \n";

	for(int i = 0; i < iNumNucleosomes; ++i)
	{
	/*	std::cout << "Modifications of nucleosome " << i << ": \n";

		cNucleosome curNucleosome = aNucleosomes[i];


		std::vector<std::string> keys;

		// Retrieve all keys

		for (std::map<std::string, std::map<int, int> >::iterator it = curNucleosome.mModifications.begin(); it != curNucleosome.mModifications.end(); it++)
			{
				std::string key = it->first;
				std::cout << "Key " << key << ": \n";
			}

		for(int j = 0; j < keys.size(); ++j)
		{
			std::cout << "Histone H2A: \n";

			std::string key = keys[j];


			int iNumMod;

			iNumMod = curNucleosome.mModifications[key].size();

			for(int j = 0; j < iNumMod; ++j)
			{
				std::cout << j << ": Histone " << keys[j] << " at site " << j << "with state " << curNucleosome.mModifications["H2A"][j] << " \n";
			}

		}

		/*
		std::cout << "Histone H2A: \n";

		int iNumMod = curNucleosome.mModifications["H2A"].size();

		for(int j = 0; j < iNumMod; ++j)
		{
			std::cout << j << ": Histone H2A at site " << j << "with state " << curNucleosome.mModifications["H2A"][j] << " \n";
		}

		std::cout << "Histone H2B: \n";

		int iNumMod = curNucleosome.mModifications["H2B"].size();

		for(int j = 0; j < iNumMod; ++j)
		{
			std::cout << j << ": Histone H2B at site " << j << "with state " << curNucleosome.mModifications["H2A"][j] << " \n";
		}*/
	}
}

