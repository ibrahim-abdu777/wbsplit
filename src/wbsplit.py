"""Split text into Unicode word-break segments (simplified UAX #29)."""


def segments(text):
    out, cur = [], []
    for ch in text:
        if ch.isspace() and cur:
            out.append("".join(cur)); cur = []
        else:
            cur.append(ch)
    if cur:
        out.append("".join(cur))
    return out


def segments_file(path):
    with open(path, "r", encoding="utf-8", errors="replace") as handle:
        return segments(handle.read())
