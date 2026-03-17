#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class DecisionTree {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        if (x[0] <= 511.5) {
                            return 0;
                        }

                        else {
                            return 1;
                        }
                    }

                protected:
                };
            }
        }
    }