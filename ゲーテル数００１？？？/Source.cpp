#include <iostream>
#include <cmath>
#include <vector>

#include "PrimeEncounterAnother.h"

int main() {
	PrimeEncounterAnother<> PEA;

	auto A = PEA.GetNth(3);

	return 0;


}

/** /
typedef std::vector<std::uint64_t> DType;


DType Filter(const DType& D, const PrimeEncounterAnother<>& PEA) {

	std::size_t j = 0;
	DType R;

	for (std::size_t i = 0; i < D.size(); i++) {

		for (j; j < PEA.Size(); j++) {
			if (PEA[j])break;
		}
		if (PEA.Size() == j)break;

		R.push_back(std::pow(j, D[i]));
		j++;
	}

	return R;
}
/**/


/** /
int main() {
	DType D{2,2,2,2,2,2 };
	PrimeEncounterAnother<> PEA;
	PEA.Search(D.size() * 16);
	auto R =	Filter(D,PEA);

	for (auto& o : R) {
		std::cout << o << std::endl;
	}

	return 0;
}
/**/