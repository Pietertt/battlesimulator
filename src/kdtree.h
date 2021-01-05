#pragma once

namespace Tmpl8 {

    class Tank;

    class KDTree {
        public:
            KDTree();
            KDTree(Tank* item);

            void add(Tank* item, int depth);
            Tank* findMin(KDTree* node, int dimension, int cd);
            void nearest_neighbour_search(KDTree* tree, Tank* tank, Tank* &current_best, float &best_distance, int depth);

            void traverse(KDTree* tree);

            KDTree* left = NULL;
            KDTree* right = NULL;

            Tank* item = NULL;

        private:
            int k = 2;


        protected:

    
    };

}