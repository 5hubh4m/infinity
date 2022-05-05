/**
 * Core - Configuration
 *
 * (c) 2018 Claude Barthels, ETH Zurich
 * Contact: claudeb@inf.ethz.ch
 *
 */

#ifndef CORE_CONFIGURATION_H_
#define CORE_CONFIGURATION_H_

#include <stdint.h>

namespace infinity {
namespace core {

class Configuration {

public:

	/**
	 * Create a config object
	 */
	Configuration(
		uint32_t sendCQLength = 16351,
		uint32_t recvCQLength = 16351,
		uint32_t sharedCQLength = 16351,
		uint32_t maxOutstanding = 16351,
		uint32_t maxScatterGather = 1
	):
		SEND_COMPLETION_QUEUE_LENGTH(sendCQLength),
		RECV_COMPLETION_QUEUE_LENGTH(recvCQLength),
		SHARED_RECV_QUEUE_LENGTH(sharedCQLength),
		MAX_NUMBER_OF_OUTSTANDING_REQUESTS(maxOutstanding),
		MAX_NUMBER_OF_SGE_ELEMENTS(maxScatterGather)
	{}

	/**
	 * Queue length settings
	 */

	const uint32_t SEND_COMPLETION_QUEUE_LENGTH;			// Must be less than MAX_CQE
                                                                        
	const uint32_t RECV_COMPLETION_QUEUE_LENGTH; 			// Must be less than MAX_CQE
                                                                        
	const uint32_t SHARED_RECV_QUEUE_LENGTH;			// Must be less than MAX_SRQ_WR
                                                                        
	const uint32_t MAX_NUMBER_OF_OUTSTANDING_REQUESTS;		// Must be less than (MAX_QP_WR * MAX_QP)
	 								// Since we use one single shared receive queue,
	 								// this number should be less than MAX_SRQ_WR
                                                                        
	const uint32_t MAX_NUMBER_OF_SGE_ELEMENTS;			// Must be less than MAX_SGE

	/**
	 * System settings
	 */

	static const uint32_t PAGE_SIZE = 4096;				// Memory regions will be page aligned by the Infinity library

	static const uint32_t MAX_CONNECTION_USER_DATA_SIZE = 1024;	// Size of the user data which can be transmitted when establishing a connection

	static constexpr const char* DEFAULT_IB_DEVICE = "ib0";		// Default name of IB device

};

} /* namespace core */
} /* namespace infinity */

#endif /* CORE_CONFIGURATION_H_ */
