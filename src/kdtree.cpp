#include "precomp.h"

namespace Tmpl8 {

    KDTree::KDTree(){

    }

    KDTree::KDTree(Tank* item){
        this->item = item;
    }

    void KDTree::add(Tank* item, int depth){
        if (this->item == NULL) {
            this->item = item;
            return;
        }

        if(depth % this->k == 0){
            if(item->get_position().x > this->item->get_position().x){
                if(this->right != NULL) this->right->add(item, depth + 1);
                if(this->right == NULL) this->right = new KDTree(item);
            } else {
                if(this->left != NULL) this->left->add(item, depth + 1);
                if(this->left == NULL) this->left = new KDTree(item);
            }
        } else {
            if(item->get_position().y > this->item->get_position().y){
                if(this->right != NULL) this->right->add(item, depth + 1);
                if(this->right == NULL) this->right = new KDTree(item);
            } else {
                if(this->left != NULL) this->left->add(item, depth + 1);
                if(this->left == NULL) this->left = new KDTree(item);
            }
        }
    }

    Tank* KDTree::findMin(KDTree* node, int dimension, int cd){
        if(node == NULL) return NULL;

        if(cd == dimension){
            if(node->left == NULL) return node->item;
            return this->left->findMin(this->left, dimension, (cd + 1) % dimension);
        } else {
            return this->left->findMin(this->left, dimension, (cd + 1) % dimension);
            return this->right->findMin(this->right, dimension, (cd + 1) % dimension);
        }
    }

    void KDTree::nearest_neighbour_search(KDTree* tree, Tank* tank, Tank* &current_best, float &best_distance, int depth){
        if(tree == NULL) return;

        KDTree* next = NULL;
        KDTree* other = NULL;

        if(depth % 2 == 0){
            if(tank->get_position().x > tree->item->get_position().x){
                next = tree->right;
                other = tree->left;
            } else {
                next = tree->left;
                other = tree->right;
            }
        } else {
            if(tank->get_position().y > tree->item->get_position().y){
                next = tree->right;
                other = tree->left;
            } else {
                next = tree->left;
                other = tree->right;
            }
        }

        this->nearest_neighbour_search(next, tank, current_best, best_distance, depth + 1);

        float distance = tank->get_distance(tank, tree->item);
        if(distance < best_distance){
            if(tank != tree->item){
                if(tree->item->active){
                     best_distance = distance;
                    current_best = tree->item;
                }
            }
        }

        float perpendicular = 0;
        if(depth % 2 == 0){
            perpendicular = tank->get_position().x - tree->item->get_position().x;
        } else {
            perpendicular = tank->get_position().y - tree->item->get_position().y;
        }

        if(distance >= (perpendicular * perpendicular)){
            this->nearest_neighbour_search(other, tank, current_best, best_distance, depth + 1);
            distance = tank->get_distance(tank, tree->item);
            if(distance < best_distance){
                if(tank != tree->item){
                    if(tree->item->active){
                        best_distance = distance;
                        current_best = tree->item;
                    }
                }
            }
        }
    }

    void KDTree::traverse(KDTree* tree){
        if(tree == NULL) return;

        std::cout << tree->item->get_position().x << " " << tree->item->get_position().y << std::endl;


        this->traverse(tree->left);
        this->traverse(tree->right);
        
    }

}