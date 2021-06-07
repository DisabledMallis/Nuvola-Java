#ifndef NUVOLA_CLIENT
#define NUVOLA_CLIENT

#include <iostream>

class Client {
	static inline Client* instance = nullptr;
	
	Client() {
		std::cout << "Initializing client..." << std::endl;

		

		std::cout << "Client initialized" << std::endl;
	}
public:
	static auto getClient() -> Client* {
		if(!instance) {
			instance = new Client();
		}
		return instance;
	}
};

#endif /* NUVOLA_CLIENT */
