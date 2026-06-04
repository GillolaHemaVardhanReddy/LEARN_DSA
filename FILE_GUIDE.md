# 🗺️ FILE GUIDE — what every file does (Hema Vardhan)

Quick map of the repo so you (and Tommy) always know where things live.

---

## Always loaded (in context every session)
| File | What it is |
|---|---|
| `CLAUDE.md` | Tommy's **operating manual** — the rules, teaching method, mastery levels. Auto-loaded at the start of every session. Don't bloat it (it's always in context = always costs tokens). |

## Memory / state (Tommy reads at start, edits as we go, commits at end)
| File | What it is | When it's touched |
|---|---|---|
| `PROGRESS.md` | Live tracker: topic **levels**, counters, session log, schedule. | Read at session start; updated on every level change. |
| `REVISION_QUEUE.md` | Spaced-repetition queue — what's due for recall, and when. | Read at start; opens each day. |
| `PATTERN_JOURNAL.md` | Per-pattern **recognition cues** + templates (the terse cheat-sheet). | After each problem / pattern. |
| `MISTAKE_JOURNAL.md` | Every mistake: root cause + re-test date + the pre-submit checklist. | When you get something wrong. |

## Planning & reference (read on demand, change rarely)
| File | What it is |
|---|---|
| `CURRICULUM.md` | The full 24-module map, problem ladders, primitives. The territory. |
| `SPRINT_PLAYBOOK.md` | How we run each topic (the 7-step loop, problems-per-topic, scoring). |
| `SPRINT_SCHEDULE.md` | June 4–9 day-by-day plan. Say a date to resume that day. |
| `FILE_GUIDE.md` | This file. |

## Your study material
| Path | What it is |
|---|---|
| `Notes/<NN>-<Topic>.md` | Plain-English **study notes** per topic — re-read these to revise. |
| `solutions/<NN>-<Topic>/<NN>-<Problem>/problem.md` | The problem card (Tommy writes). |
| `solutions/<NN>-<Topic>/<NN>-<Problem>/solution.cpp` | Your code (you write). |

## Tooling / config
| File | What it is |
|---|---|
| `run.sh` | Build + run a `.cpp` locally, fixing the macOS linker bug. Usage: `./run.sh <path>`. |
| `.mcp.json` | LeetCode MCP server config. **Gitignored** — holds your login cookie, never committed. |
| `.vscode/settings.json` | Turns off AI autocomplete in this repo (so you think for yourself). |
| `.claude/commands/*.md` | Slash commands (loaded **on demand** only when you type them — token-cheap). |

---

## 💡 Token & workflow tips
- **One session per day.** End with `/endsession`, quit, and next day open fresh + `/continue`.
  A fresh session drops the chat history (the main token cost); your memory is in the committed
  files, so nothing is lost. This is the biggest token saver — bigger than anything else.
- Memory lives in **committed files**, not the chat. `git log` is your real progress history.
- Slash commands are already the efficient "load only when needed" pattern — that's what
  `.claude/commands/` is for.

## ⌨️ Commands you have
`/continue` · `/dashboard` · `/revise` · `/drill` (name-the-pattern) · `/interview` ·
`/logmistake` · `/recap-patterns` (5 Qs/pattern exam) · `/endsession`
Plus: type **`STUCK`** during a problem to get exactly one hint up the ladder.
