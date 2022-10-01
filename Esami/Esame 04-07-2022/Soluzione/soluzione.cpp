#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

template <typename T>
class AbstractRandomGenerator {
	protected:
		int num_values;
		int tossed;
		T accumulated_value;
		T value;
		T* values;
	
	public:
		AbstractRandomGenerator(T value, int num_values, T *input_values) {
			this->value = value;
			this->num_values = num_values;
			this->values = new T[num_values];
			accumulated_value = value;
			tossed = 0;
			for(int i=0; i<num_values; i++) {
				this->values[i] = input_values[i];
			}
		}

		virtual T toss() {
			value = values[rand()%num_values];
			tossed++;
			accumulated_value+=value;
			return value;
		}

		T getValue() {
			return value;
		}

		int getTossed() {
			return tossed;
		}

		virtual void nudge() = 0;

		virtual ostream& print(ostream& os) {
            os << ", values={ ";
			for(int i=0; i<num_values; i++)
				os << values[i]<<" ";
			os <<"}, value="<<value<<", accumulated_value="<<accumulated_value<<", tossed="<<tossed;
            return os;
        }
};

template <typename T>
ostream& operator<<(ostream& os, AbstractRandomGenerator<T>& w) {
    return w.print(os);
}

class Dice : public AbstractRandomGenerator<int> {
	private:
		int doubles;
	public:
		Dice() : AbstractRandomGenerator<int>(1, 6, new int[6]{1,2,3,4,5,6}), doubles(0) {}
		void nudge() {
			value=rand() % 3-1;
			if(value<1)
				value=1;
			if(value>6)
				value=6;
		}

		int toss() {
			int previous_value = value;
			int value = AbstractRandomGenerator<int>::toss();
			if(value==previous_value) {
				doubles++;
			}

			return value;
		}

		double getDoubleRate() {
			return double(doubles)/tossed;
		}

		ostream& print(ostream& os) {
            os << "Class=" << typeid(this).name();
            AbstractRandomGenerator::print(os);
            return os;
        }
};

class Coin: public AbstractRandomGenerator<string> {
	private:
		int nudge_prob;
	public:
		Coin(int nudge_prob): AbstractRandomGenerator<string>("H", 2, new string[2]{"H","T"}), nudge_prob(nudge_prob) {}
		void nudge() {
			if((rand()%nudge_prob)==0) {
				if(value=="H")
					value="T";
				else
					value="H";
			}
		}

		ostream& print(ostream& os) {
            os << "Class=" << typeid(this).name();
            AbstractRandomGenerator::print(os);
            return os;
        }
};

int main() {
    int DIM = 7;

	AbstractRandomGenerator<int> **vec1 = new AbstractRandomGenerator<int>*[DIM];
	AbstractRandomGenerator<string> **vec2 = new AbstractRandomGenerator<string>*[DIM];

    srand(424242);

	for(int i=0; i<DIM; i++) {
		vec1[i] = new Dice();
		vec2[i] = new Coin(rand()%10+1);
	}

    for(int i=0; i<100; i++) {
         vec1[rand()%DIM]->toss();
		 vec2[rand()%DIM]->toss();
         if(rand()%5==0) {
            vec1[rand()%DIM]->nudge();
			vec2[rand()%DIM]->nudge();
		 }
    }

    // PUNTO 1
    for (int i=0; i<DIM; i++) {
        cout << i+1 << ")" << *vec1[i] << endl;
		cout << i+1 << ")" << *vec2[i] << endl;
    }

	// PUNTO 2
	int min_tossed = vec2[0]->getTossed();

    for (int i=0; i<DIM; i++) {
		int tossed = vec2[i]->getTossed();
        if (tossed < min_tossed) {
            min_tossed = tossed;
        }
    }
	cout << "min tossed = "<<min_tossed<<endl;

    // PUNTO 3
    double max_double_rate= 0;
    for (int i=0; i<DIM; i++) {
		double double_rate = ((Dice*)vec1[i])->getDoubleRate();
        if (double_rate > max_double_rate) {
            max_double_rate = double_rate;
        }
    }

    cout << "max double rate = "<<max_double_rate<<endl;
}