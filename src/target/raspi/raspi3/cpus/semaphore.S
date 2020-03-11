.global _semaphorei
.global _semaphored

.section .text

_semaphorei:
    b _semaphorei

_semaphored:
    b _semaphored