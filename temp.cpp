int BinarySearch(const Database& database, const string& word, int low, int high)
{
    // since this is a recursive function it's possible that a call
    // back in to this function may have a high that is now lower than
    // the low. If so check if the word is of > value (sort order)
    // than the low word. If so return the next word after the lowest,
    // if the word is not of > value (sort order) then just return the
    // low index to the array.
    if (high <= low)
    {
        // if the low word is empty return it as the idx as empty space
        // indicates an element that can be set.
        if (database.records[low].word.size() == 0) return low;

        return (word > database.records[low].word) ? (low + 1) : low;
    }

    // Find the next mid point in the new consolidated range of the array.
    int mid = (low + high) / 2;

    // check the mid point word to see if they are equal. If they are
    // equal return the mid point idx. This makes the assumption that
    // duplicate words will not be duplicated in the array but that they
    // will be incremented in the occurence. The word comparison check
    // should occur by the caller of this function and update the word
    // occurence accordingly.
    if (word == database.records[mid].word)
    {
        return mid;
    }

    // If the word is greater value than the current mid point search
    // the right side of the array. This includes a recursive call back
    // in to this function with the low end of the range to search
    // being set to the next word after the current midpoint
    if (word > database.records[mid].word)
    {
        return BinarySearch(database, word, mid + 1, high);
    }

    // If the word is of less value than the current mid point then
    // search the left side of this range. This means a recursive
    // call in to this function with current low index and a high end
    // of the range set to the word right before the mid point
    return BinarySearch(database, word, low, mid - 1);
}
