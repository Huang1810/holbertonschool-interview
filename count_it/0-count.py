#!/usr/bin/python3
"""
Recursive function to query Reddit API and count keywords in hot article titles
"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """
    Recursively queries the Reddit API, parses titles of hot articles, and
    prints a sorted count of given keywords.
    """
    if counts is None:
        # Normalize keywords: lowercase and account for duplicates
        counts = {}
        for word in word_list:
            lw = word.lower()
            counts[lw] = counts.get(lw, 0)

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "custom"}
    params = {"after": after, "limit": 100}

    try:
        response = requests.get(url, headers=headers,
                                params=params, allow_redirects=False)
    except Exception:
        return

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    children = data.get("children", [])
    after = data.get("after", None)

    # Process each title
    for child in children:
        title = child.get("data", {}).get("title", "").lower()
        words = title.split()
        for word in words:
            # only count if exact match (no punctuation attached)
            if word in counts:
                counts[word] += 1

    # Recursive call if more pages exist
    if after is not None:
        return count_words(subreddit, word_list, after, counts)

    # Done → print results
    # Filter out words with zero count
    results = {k: v for k, v in counts.items() if v > 0}
    if not results:
        return

    # Sort: first by count desc, then alphabetically asc
    sorted_results = sorted(results.items(),
                            key=lambda x: (-x[1], x[0]))

    for word, count in sorted_results:
        print(f"{word}: {count}")
