#pragma once
#include <vector>
#include <cstdint>
#include <cmath>

//エラトステネスの篩型プライムエンカウンター。

template<class T = std::size_t> 
class PrimeEncounterAnother {
public:
	typedef std::vector<bool> PrimeSet;
	typedef T Integer;

	PrimeEncounterAnother(){
		Clear();
	}

	bool Clear() {
		Primes.clear();
		if (Primes.size() == 0) {
			Primes.push_back(true);
			Primes.push_back(true);
			Searched = 1;
		}
		return true;
	}

	bool Search(const Integer& N){
		if (Searched >= N) return false;
		Integer L = static_cast<Integer>(std::sqrt(N))+1;
		Primes.resize(N+1);
		for (Integer i = 0; i < L; i++) {
			if (Primes[i] == true) continue;
			for (Integer j = (Searched / i)+1; i*j <= N; j++) {
				if (j <= 1)continue;
				Primes[i*j] = true;
			}
		}
		Searched = N + 1;
		return true;
	}
	Integer IsSearched() const{
		return Searched;
	}
	Integer Size() const {
		return Primes.size();
	}
	Integer GetNth(const Integer& N) {
		Integer C = 0;

		Search(N * 16);

		for (std::size_t i = 2; i <Size(); i++) {
			if ((*this)[i])C++;
			if (C == N)return i;
		}
		return 0;
	}
	bool operator [](const Integer& Idx) const {
		return !Primes[Idx];
	}
protected:
	PrimeSet Primes;
	Integer Searched;
};