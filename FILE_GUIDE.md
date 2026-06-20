# 🗺️ FILE GUIDE — what every file does (Hema Vardhan)

Quick map of the repo so you (and Kira) always know where things live.

---

## 🚪 The front door (read FIRST, every session)
| File | What it is |
|---|---|
| `COMMAND_CENTER.md` | **The single front door.** Today's plan + per-topic hub (level · video · solved · open leaks · next action) + mode legend (learn/practice/test) + the **leak scoreboard** (your execution bottleneck + first-submit-clean streak). Indexes everything; doesn't duplicate it. |
| `CHECKLIST.md` | Your **pre-flight ritual** (Gate A restate · Gate B reduction-attack · Gate C boundary/overflow/container) — you run it out loud, Kira verifies. Plus the reusable **stress-test harness**. |

## Always loaded (in context every session)
| File | What it is |
|---|---|
| `CLAUDE.md` | Kira's **operating manual** — the rules, teaching method, mastery levels. Auto-loaded at the start of every session. Don't bloat it (it's always in context = always costs tokens). |

## Memory / state (Kira reads at start, edits as we go, commits at end)
| File | What it is | When it's touched |
|---|---|---|
| `PROGRESS.md` | Live tracker: topic **levels**, counters, session log, schedule. | Read at session start; updated on every level change. |
| `REVISION_QUEUE.md` | Spaced-repetition queue — what's due for recall, and when. | Read at start; opens each day. |
| `PATTERN_JOURNAL.md` | Per-pattern **recognition cues** + templates (the terse cheat-sheet). | After each problem / pattern. |
| `MISTAKE_JOURNAL.md` | Every mistake: root cause + re-test date + the pre-submit checklist. | When you get something wrong. |
| `LEARNING_PROFILE.md` | Kira's model of **how you learn** (which hints land, confusion shapes). | When something is learned about *how* you learn. |

## Planning & reference (read on demand, change rarely)
| File | What it is |
|---|---|
| `CURRICULUM.md` | The full 24-module map, problem ladders, primitives. The territory. |
| `SPRINT_PLAYBOOK.md` | How we run each topic (the 7-step loop, problems-per-topic, scoring). |
| `SPRINT_SCHEDULE.md` | June 4–9 day-by-day plan. Say a date to resume that day. |
| `FILE_GUIDE.md` | This file. |

## Your study material — split by the 3 MODES (this is why there are 3 folders)
| Path | Mode | What it is |
|---|---|---|
| `Notes/<NN>-<Topic>.md` | — | Plain-English **study notes** per topic — re-read to revise. |
| `learn/<NN>-<Topic>/<NN>-<Problem>/` | **LEARN** | First-time guided solves (Socratic, brute→bridge→optimal). `problem.md` (Kira) + `solution.cpp` (you). |
| `practice/<NN>-Topic/` · `practice/drills/drillN/` · `practice/day-NN/` | **PRACTICE** | Reps & calibration: topic mastery sets, the disguised escalating drill series, daily cold sets. No level promotion. |
| `test/cold-recognition/` · `/drill` · `/interview` | **TEST** | Cold, closed-book — the ONLY mode that promotes L4→L5. |

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
