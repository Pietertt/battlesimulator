#pragma once

namespace Tmpl8 {

    class Tank;

    class KDTree {
        public:
            KDTree();
            KDTree(Tank* item);
            void add(Tank* item, int depth);

            KDTree* left = NULL;
            KDTree* right = NULL;

            Tank* item = NULL;

        private:


        protected:

    
    };

}