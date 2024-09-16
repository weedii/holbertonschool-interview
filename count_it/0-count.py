#!/usr/bin/python3

import requests


def count_words(subreddit, word_list, after=None):
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"

    counts = {word.lower(): 0 for word in word_list}

    # Parameters for pagination
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        response = requests.get(url, params=params, allow_redirects=False)

        if response.status_code != 200:
            return

        data = response.json()

        posts = data.get("data").get("children")

        for post in posts:
            title = post.get("data").get("title").lower().split()

            for word in title:
                for keyword in counts.keys():
                    if word == keyword:
                        counts[keyword] += 1

        after = data.get("data").get("after")

        # If there's more data, continue fetching
        if after:
            return count_words(subreddit, word_list, after)

    except Exception as e:
        return

    # sort based on count
    sorted_counts = sorted(
        [(word, count) for word, count in counts.items() if count > 0],
        key=lambda x: (-x[1], x[0]),
    )

    for word, count in sorted_counts:
        print(f"{word}: {count}")
