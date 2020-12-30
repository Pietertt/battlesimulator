#include "precomp.h"

namespace Tmpl8 {

    KDTree::KDTree(){

    }

    KDTree::KDTree(Tank* item){
        this->item = item;
    }

    void KDTree::add(Tank* item, int depth){
        if (this->item == NULL) this->item = item;

        if(depth % 2 == 0){
            if(item->get_position().y < this->item->get_position().y){
                if(this->left != NULL){
                    this->left->add(item, depth + 1);
                } else {
                    this->left = new KDTree(item);
                }
            } else {
                if(this->right != NULL){
                    this->right->add(item, depth + 1);
                } else {
                    this->right = new KDTree(item);
                }
            } 
        } else {
            if(item->get_position().x < this->item->get_position().x){
                if(this->left != NULL){
                    this->left->add(item, depth + 1);
                } else {
                    this->left = new KDTree(item);
                }
            } else {
                if(this->right != NULL){
                    this->right->add(item, depth + 1);
                } else {
                    this->right = new KDTree(item);
                }
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

    Tank* KDTree::search(Tank* item, int depth) {
        if(this->item == NULL) return NULL;
        Tank* best = NULL;

        if(best == NULL){
            best = this->item;
        }

        if(depth % 2 == 0){
            (item->get_position().x < this->item->get_position().x) ? this->left->search(item, depth + 1) : this->right->search(item, depth + 1);
        } else {
            (item->get_position().y < this->item->get_position().y) ? this->left->search(item, depth + 1) : this->right->search(item, depth + 1);
        }
    }

    void KDTree::traverse(){
        if(this->left != NULL){
            std::cout << this->left->item->get_position().x << " " << this->left->item->get_position().y << std::endl;
            this->left->traverse();
        }

        if(this->right != NULL){
            std::cout << this->right->item->get_position().x << " " << this->right->item->get_position().y << std::endl;
            this->right->traverse();
        }
    }

}