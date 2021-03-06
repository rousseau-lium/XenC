#include "../../../../include/kenlm/lm/common/renumber.hh"
#include "../../../../include/kenlm/lm/common/ngram.hh"

#include "../../../../include/kenlm/util/stream/stream.hh"

namespace lm {

void Renumber::Run(const util::stream::ChainPosition &position) {
  for (util::stream::Stream stream(position); stream; ++stream) {
    NGramHeader gram(stream.Get(), order_);
    for (WordIndex *w = gram.begin(); w != gram.end(); ++w) {
      *w = new_numbers_[*w];
    }
  }
}

} // namespace lm
