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
            if(item->get_position().x >= this->item->get_position().x){
                if(this->right != NULL) this->right->add(item, depth + 1);
                if(this->right == NULL) this->right = new KDTree(item);
            } else {
                if(this->left != NULL) this->left->add(item, depth + 1);
                if(this->left == NULL) this->left = new KDTree(item);
            }
        } else {
            if(item->get_position().y >= this->item->get_position().y){
                if(this->right != NULL) this->right->add(item, depth + 1);
                if(this->right == NULL) this->right = new KDTree(item);
            } else {
                if(this->left != NULL) this->left->add(item, depth + 1);
                if(this->left == NULL) this->left = new KDTree(item);
            }
        }
    }

    bool KDTree::search(Tank* item, int depth) {
        if(this->item == NULL) return false;

        if(this->item == item) return true;

        if(depth % this->k == 0){
            if(item->get_position().x > this->item->get_position().x) return right->search(item, depth + 1);
            return left->search(item, depth + 1);
        } else {
            if(item->get_position().y > this->item->get_position().y) return right->search(item, depth + 1);
            return left->search(item, depth + 1);
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

        float distance = tank->get_distance(tank, tree->item);

        if(distance < best_distance){
            if(tank != tree->item){
                best_distance = distance;
                current_best = tree->item;
            }
        }

        std::cout << tank->get_position().x << " " << tank->get_position().y << " " << " : " << distance << " : " << tree->item->get_position().x << " " << tree->item->get_position().y << std::endl;

        if(tank->compare_position(tree->item, depth)){
            tree->nearest_neighbour_search(tree->right, tank, current_best, best_distance, depth + 1);
        } else {
            tree->nearest_neighbour_search(tree->left, tank, current_best, best_distance, depth + 1);
        }
    }

    // Tank* KDTree::search(Tank* item, int depth) {
    //     if(this->item == NULL) return NULL;
    //     Tank* best = NULL;

    //     if(best == NULL){
    //         best = this->item;
    //     }

    //     if(depth % 2 == 0){
    //         (item->get_position().x < this->item->get_position().x) ? this->left->search(item, depth + 1) : this->right->search(item, depth + 1);
    //     } else {
    //         (item->get_position().y < this->item->get_position().y) ? this->left->search(item, depth + 1) : this->right->search(item, depth + 1);
    //     }
    // }

    void KDTree::traverse(KDTree* tree){
        if(tree == NULL) return;

        std::cout << tree->item->get_position().x << " " << tree->item->get_position().y << std::endl;


        this->traverse(tree->left);
        this->traverse(tree->right);
        
    }

}