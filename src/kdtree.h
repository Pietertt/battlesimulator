#pragma once

namespace Tmpl8 {

    class Tank;

    class KDTree {
        public:
            KDTree();
            KDTree(Tank* item);

            void add(Tank* item, int depth);
            Tank* search(Tank* item, int depth);
            Tank* findMin(KDTree* node, int dimension, int cd);

            void traverse();

            KDTree* left = NULL;
            KDTree* right = NULL;

            Tank* item = NULL;

        private:


        protected:

    
    };

}